#!/usr/bin/python3
"""Script that lists all """
import sys

import MySQLdb


def list_states(username, password, database):
    """lists all states from the database hbtn_0e_0_usa."""

    db = MySQLdb.connect(
        host="localhost",
        port=3306,
        user=username,
        passwd=password,
        db=database
    )

    cursor = db.cursor()

    cursor.execute(
        (
                "SELECT city.id, city.name, st.name \
                FROM cities city, states st \
                WHERE city.state_id = st.id \
                ORDER BY city.id"
        )
    )

    rows = cursor.fetchall()

    [print(row) for row in rows]

    db.close()


if __name__ == "__main__":
    username = sys.argv[1]

    password = sys.argv[2]

    database = sys.argv[3]

    list_states(username, password, database)
