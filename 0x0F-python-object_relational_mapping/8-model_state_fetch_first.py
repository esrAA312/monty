#!/usr/bin/python3
"""Script to list all State objects from the database hbtn_0e_6_usa."""

from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from model_state import Base, State
from sys import argv

if __name__ == "__main__":

    mysql_username = argv[1]
    mysql_password = argv[2]
    database_name = argv[3]
    engine = create_engine('mysql+mysqldb://{}:{}@localhost:3306/{}'
                           .format(mysql_username, mysql_password,
                                   database_name))

    Base.metadata.bind = engine
    Session = sessionmaker(bind=engine)
    session = Session()
    one = session.query(State).order_by(State.id).first()

    if one is not None:
        print("{}: {}".format(one.id, one.name))
    else:
        print("Nothing")
