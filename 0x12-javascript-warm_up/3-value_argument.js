#!/usr/bin/node

const argument = process.argv[2];
const output = argument === undefined ? 'No argument' : argument;

console.log(output);
