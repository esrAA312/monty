#!/usr/bin/python3
"""
Python script that returns information using REST API.

Returns to-do list information for a given employee ID.
"""

import requests
import sys


def fetch_employee_tasks(employee_id):
    """
    Fetches and prints the to-do list information for a given employee ID.

    Args:
    - employee_id: The ID of the employee to fetch tasks for.
    """
    # Base URL for the JSONPlaceholder API
    url = "https://jsonplaceholder.typicode.com/"

    # Get the employee information using the provided employee ID
    user = requests.get(url + "users/{}".format(employee_id)).json()

    # Get the to-do list for the employee using the provided employee ID
    params = {"userId": employee_id}
    todos = requests.get(url + "todos", params).json()

    # Filter completed tasks and count them
    completed = [t.get("title") for t in todos if t.get("completed")]

    # Print the employee's name and the number of completed tasks
    print(
        "Employee {} is done with tasks({}/{}):".format(
            user.get("name"), len(completed), len(todos)
        )
    )

    # Print the completed tasks one by one with indentation
    [print("\t {}".format(complete)) for complete in completed]


if __name__ == "__main__":
    # Check if an employee ID is provided as a command-line argument
    if len(sys.argv) < 2:
        print("Usage: python3 script.py <employee_id>")
        sys.exit(1)

    # Get the employee ID from the command-line argument
    employee_id = sys.argv[1]

    # Fetch and print the to-do list information for the provided employee ID
    fetch_employee_tasks(employee_id)
