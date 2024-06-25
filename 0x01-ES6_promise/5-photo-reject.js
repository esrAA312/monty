export default function uploadPhoto(filename) {
  return new Promise((resolve, reject) => {
    // Simulate error handling
    reject(new Error(`${filename} cannot be processed`));
  });
}
