#!/usr/bin/node
const SquareP = require('./5-square');

module.exports = class Square extends SquareP {
  charPrint (c) {
    if (c === undefined) {
      c = 'X';
    }
    let X = 0;
    while (X < this.height) {
      let s = '';
      let Y = 0;
      while (Y < this.width) {
        s += c;
        Y++;
      }
      console.log(s);
      X++;
    }
  }
};
