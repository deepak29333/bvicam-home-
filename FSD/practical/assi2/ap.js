import { writeFileSync } from 'fs';
let student = { 
    name: 'Mike',
    age: 23, 
    gender: 'Male',
    department: 'English',
    car: 'Honda' 
};
 
writeFileSync(path.resolve(__dirname, 'db.json'), JSON.stringify(student));
