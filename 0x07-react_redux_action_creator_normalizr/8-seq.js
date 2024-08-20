import { Seq } from 'immutable';

export default function printBestStudents(object) {
  const seq = Seq(object);

  const ilte = seq.filter((student) => {
    student.firstName.charAt(0).toUpperCase();
    return student.score > 70;
  });

  function capFirstLetter(string) {
    return string.charAt(0).toUpperCase() + string.slice(1);
  }

  const oo = ilte.toJS();

  Object.keys(oo).map((key) => {
    oo[key].firstName = capFirstLetter(oo[key].firstName);
    oo[key].lastName = capFirstLetter(oo[key].lastName);
    return oo[key];
  });

  console.log(oo);
}
