#!/usr/bin/node
exports.nbOccurences = function (list, searchElement) {
  let nOccurrences = 0;
  for (const element of list) {
    nOccurrences += element === searchElement ? 1 : 0;
  }
  return nOccurrences;
};
