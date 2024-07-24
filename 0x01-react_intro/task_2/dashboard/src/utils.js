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

function getLatestNotification() {
  const eod = '- complete by EOD';
  const lastnotify = <strong>Urgent requirement</strong> + eod;
  return lastnotify;
}

export {getFullYear, getFooterCopy, getLatestNotification};
