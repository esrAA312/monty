#!/usr/bin/python3

"""
    this module contains a Base and City class
"""

from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import ForeignKey
from sqlalchemy import Column, Integer, String

Base = declarative_base()


class City(Base):
    """
    City class inherits the Base class
    """

    __tablename__ = "cities"

    id = Column(Integer, primary_key=True, autoincrement=True, nullable=False)
    name = Column(String(128), nullable=False)
    state_id = Column(Integer, ForeignKey("states.id"), nullable=False)
