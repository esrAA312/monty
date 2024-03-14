from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from relationship_state import State
from relationship_city import Base, City


def add_city_state(username, password, database):
    engine = create_engine(
        "mysql+mysqldb://{}:{}@localhost:3306/{}".format(username, password, database),
        pool_pre_ping=True,
    )

    Base.metadata.create_all(engine)

    Session = sessionmaker(bind=engine)

    session = Session()

    state = State(name="California")
    city = City(name="San Francisco", state=state)

    session.add(state)
    session.add(city)
    session.commit()


if __name__ == "__main__":
    add_city_state(sys.argv[1], sys.argv[2], sys.argv[3])
