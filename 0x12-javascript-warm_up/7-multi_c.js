#!/usr/bin/node
const occurrences = process.argv[2];

if (occurrences === undefined || isNaN(parseInt(occurrences))) {
  console.log('Missing number of occurrences');
} else {
  const x = parseInt(occurrences);

  for (let i = 0; i < x; i++) {
    console.log('C is fun');
  }
}
