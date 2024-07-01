export default function cleanSet(set, startString) {
  if (!startString) return '';

  let R = '';

  for (const V of set) {
    if (V.startsWith(startString)) {
      if (R) R += '-';
      R += V.slice(startString.length);
    }
  }

  return R;
}
