#!/usr/bin/node
module.exports = class Rectangle {
  constructor (w, h) {
    if (w > 0 && h > 0) {
      this.width = w;
      this.height = h;
    }
  }

  print () {
    const XshapeRow = 'X'.repeat(this.width);

    for (let m = 0; m < this.height; m++) {
      console.log(XshapeRow);
    }
  }
};
