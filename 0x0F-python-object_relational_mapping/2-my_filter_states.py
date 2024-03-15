#!/usr/bin/python3

import sys

import MySQLdb


def list_states(username, password, database, state_name):
    """lists all states from the database hbtn_0e_0_usa."""
    db = MySQLdb.connect(user=username, passwd=password, db=database)

    cursor = db.cursor()

    cursor.execute("SELECT * FROM states WHERE name = BINARY '{}' \
    ORDER BY states.id".format(state_name))

    rows = cursor.fetchall()

    [print(row) for row in rows]

    db.close()


if __name__ == "__main__":
    username = sys.argv[1]

    password = sys.argv[2]

    database = sys.argv[3]

    state_name = sys.argv[4]

    list_states(username, password, database, state_name)
