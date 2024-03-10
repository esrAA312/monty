#!/usr/bin/node
const add = (a, b) => {
  const c = a + b;
  console.log(c);
};

const arg1 = Number(process.argv[2]);
const arg2 = Number(process.argv[3]);

add(arg1, arg2);
