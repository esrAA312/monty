#!/usr/bin/python3
"""Module that retrieves and prints all cities."""
import sys
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from relationship_state import State
from relationship_city import City
from relationship_state import Base, State

if __name__ == "__main__":
    us = sys.argv[1]
    pa = sys.argv[2]
    na = sys.argv[3]

    engine = create_engine(
        "mysql+mysqldb://{}:{}@localhost:3306/{}".format(us, pa, na), pool_pre_ping=True
    )

    Base.metadata.create_all(engine)

    Session = sessionmaker(bind=engine)

    session = Session()

    cities = session.query(City).join(State).order_by(City.id)

    for city in cities:
        print("{}: {} -> {}".format(city.id, city.name, city.state.name))

    session.close()
