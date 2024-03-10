#!/usr/bin/node

exports.callMeMoby = function (x, theFunction) {
  let m = 0;
  while (m < x) {
    theFunction();
    m++;
  }
};
