export default function guardrail(mathFunction) {
  const queue = [];

  try {
    // Execute the mathFunction and append the result to the queue
    const result = mathFunction();
    queue.push(result);
  } catch (error) {
    // If an error is thrown, append the error message to the queue
    queue.push(`Error: ${error.message}`);
  } finally {
    // Append the guardrail message to the queue in all cases
    queue.push('Guardrail was processed');
  }

  return queue;
}
