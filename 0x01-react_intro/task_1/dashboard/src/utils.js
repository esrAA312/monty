/* A function to return the current year 
*/

function getFullYear() {
  const thisYear = new Date();
  return thisYear.getFullYear();
}

function getFooterCopy(isIndex) {
  if(isIndex) {
    return 'Holberton School';
  }
  return 'Holberton School main dashboard';
}

export {getFullYear, getFooterCopy};
