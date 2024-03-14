#!/usr/bin/python3
"""Adds a new state to the database."""

import sys
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from model_state import State


def add_new_state(username, password, database, state_name):
    # Create the SQLAlchemy engine
    engine = create_engine(
        "mysql+mysqldb://{}:{}@localhost/{}".format(username, password, database),
        pool_pre_ping=True,
    )

    Session = sessionmaker(bind=engine)
    session = Session()
    new_state = State(name=state_name)

    session.add(new_state)
    session.commit()

    print(new_state.id)


if __name__ == "__main__":
    add_new_state(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])
