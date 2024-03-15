#!/usr/bin/python3
""" prints the State object with the name passed as argument from the database
"""
import sys
from model_state import Base, State
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker


def update_state_name(username, password, database):
    """
    Update the name of a State object with the given ID in the database.

    """
    engine = create_engine(
        "mysql+mysqldb://{}:{}@localhost:3306/{}".format(
            username, password, database, pool_pre_ping=True
        )
    )
    Base.metadata.create_all(engine)
    Session = sessionmaker(bind=engine)
    session = Session()
    state = session.query(State).filter_by(id=2).first()
    if state:
        state.name = "New Mexico"
        session.commit()


if __name__ == "__main__":
    update_state_name(
        sys.argv[1], sys.argv[2], sys.argv[3]
    )
