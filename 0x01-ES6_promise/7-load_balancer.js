export default function loadBalancer(chinaDownload, USDownload) {
  // Return the value of the first Promise to resolve
  return Promise.race([chinaDownload, USDownload]);
}
