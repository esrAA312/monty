import { uploadPhoto, createUser } from './utils';

export default function handleProfileSignup() {
  return Promise.all([uploadPhoto(), createUser()])
    .then(([ph, us]) => {
      console.log(`${ph.body} ${us.firstName} ${us.lastName}`);
    })
    .catch(() => {
      console.log('Signup system offline');
    });
}
