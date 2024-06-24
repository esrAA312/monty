export default function taskBlock(trueOrFalse) {
  const task = false;
  const task2 = true;

  if (trueOrFalse) {
    // This block is now empty as the variables were not contributing to the return value
  }

  return [task, task2];
}
