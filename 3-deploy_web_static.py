#!/usr/bin/python3
"""
Fabric script that generates a tgz  AirBnB Clone repo
"""

from fabric.api import env, local, put, run
from datetime import datetime
from os.path import exists, isdir
env.hosts = ["3.84.238.226", "54.84.245.120"]


def do_pack():
    """
    Generates a tgz archive in the web_static folder
    """
    try:
        current_datetime = datetime.now().strftime("%Y%m%d%H%M%S")
        if not isdir("versions"):
            local("mkdir -p versions")
        file_name = "versions/web_static_{}.tgz".format(current_datetime)
        local("tar -cvzf {} web_static".format(file_name))
        return file_name
    except Exception as e:
        print("An error occurred:", e)
        return None


def do_deploy(archive_path):
    """distributes an archive to the web servers"""
    if exists(archive_path) is False:
        return False
    try:
        file_n = archive_path.split("/")[-1]
        no_ext = file_n.split(".")[0]
        path = "/data/web_static/releases/"
        put(archive_path, '/tmp/')
        run('mkdir -p {}{}/'.format(path, no_ext))
        run('tar -xzf /tmp/{} -C {}{}/'.format(file_n, path, no_ext))
        run('rm /tmp/{}'.format(file_n))
        run('mv {0}{1}/web_static/* {0}{1}/'.format(path, no_ext))
        run('rm -rf {}{}/web_static'.format(path, no_ext))
        run('rm -rf /data/web_static/current')
        run('ln -s {}{}/ /data/web_static/current'.format(path, no_ext))
        return True
    except Exception as e:
        return False


def deploy():
    """creates anrs"""
    archive_path = do_pack()
    if archive_path is None:
        return False
    return do_deploy(archive_path)
