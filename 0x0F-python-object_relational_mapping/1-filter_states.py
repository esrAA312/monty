#!/usr/bin/python3
"""all states from mySQL database"""
import sys

import MySQLdb


def list_states(username, password, database):
    """lists all states from the database hbtn_0e_0_usa."""
    db = MySQLdb.connect(user=username, passwd=password, db=database)

    cursor = db.cursor()

    cursor.execute("SELECT * FROM states ORDER BY states.id")

    rows = cursor.fetchall()

    [print(row) for row in rows if row[1][0] == "N"]

    db.close()


if __name__ == "__main__":
    username = sys.argv[1]

    password = sys.argv[2]

    database = sys.argv[3]

    list_states(username, password, database)
