#!/usr/bin/python3
"""prints a list of cities with their
"""
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from model_state import State
from model_city import City


def print_cities(username, password, database):
    engine = create_engine(
        f"mysql+mysqldb://{username}:{password}@localhost/{database}",
        pool_pre_ping=True,
    )

    Session = sessionmaker(bind=engine)
    session = Session()
    for city, state in (
        session.query(City, State).filter(City.state_id == State.id).order_by(City.id)
    ):
        print(f"{state.name}: ({city.id}) {city.name}")


if __name__ == "__main__":
    print_cities(sys.argv[1], sys.argv[2], sys.argv[3])
