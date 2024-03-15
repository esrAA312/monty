#!/usr/bin/python3

import sys

import MySQLdb


def list_states(username, password, database, state_name):
    """lists all states from the database hbtn_0e_0_usa."""
    db = MySQLdb.connect(host='localhost',\
        port=3306,\
        user=username,\
        passwd=password,\
        db=database
    )

    cursor = db.cursor()

    cursor.execute(
        "SELECT * FROM `cities` as `ct` \
                INNER JOIN `states` as `s` \
                   ON `ct`.`state_id` = `s`.`id` \
                ORDER BY `ct`.`id`"
    )
    print(", ".join([ct[2] for ct in c.fetchall() if ct[4] == sys.argv[4]]))
    db.close()


if __name__ == "__main__":
    username = sys.argv[1]

    password = sys.argv[2]

    database = sys.argv[3]

    state_name = sys.argv[4]

    list_states(username, password, database, state_name)
