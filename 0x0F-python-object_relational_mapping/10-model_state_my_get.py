#!/usr/bin/python3
"""Module that retrieves and prints a state ID from a MySQL database using SQLAlchemy."""

import sys
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from model_state import State, Base


def get_state_id(username, password, database, state_name):
    """
    Retrieve and print the ID of a state from a MySQL database.
    """
    engine = create_engine(
        "mysql+mysqldb://{}:{}@localhost/{}".format(username, password, database),
        pool_pre_ping=True,
    )
    Base.metadata.create_all(engine)
    Session = sessionmaker(bind=engine)
    session = Session()

    found = False
    for state in session.query(State):
        if state.name == state_name:
            print("{}".format(state.id))
            found = True
            break

    if not found:
        print("Not found")


if __name__ == "__main__":
    get_state_id(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])
