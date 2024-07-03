interface Student {
  firstName: string;
  lastName: string;
  age: number;
  location: string;
}

const student1: Student = {
  firstName: 'Yusra',
  lastName: 'Yahya',
  age: 24,
  location: 'Sudan'
};

const student2: Student = {
  firstName: 'Esraa',
  lastName: 'Yahya',
  age: 22,
  location: 'Sudan'
};

const studentsList: Student[] = [student1, student2];

function renderTable() {
  const table = document.createElement('table');

  const headerRow = document.createElement('tr');
  const headerFirstName = document.createElement('th');
  const headerLocation = document.createElement('th');

  headerFirstName.textContent = 'First Name';
  headerLocation.textContent = 'Location';

  headerRow.appendChild(headerFirstName);
  headerRow.appendChild(headerLocation);
  table.appendChild(headerRow);

  studentsList.forEach(student => {
    const row = document.createElement('tr');
    const firstNameCell = document.createElement('td');
    const locationCell = document.createElement('td');

    firstNameCell.textContent = student.firstName;
    locationCell.textContent = student.location;

    row.appendChild(firstNameCell);
    row.appendChild(locationCell);
    table.appendChild(row);
  });

  document.body.appendChild(table);
}

renderTable();
