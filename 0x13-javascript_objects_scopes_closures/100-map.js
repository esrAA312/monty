#!/usr/bin/node
const { list } = require('./100-data');
const newList = list.map((X, index) => X * index);
console.log(list);
console.log(newList);
