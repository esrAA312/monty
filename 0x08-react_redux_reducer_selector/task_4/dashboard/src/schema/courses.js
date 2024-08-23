import { schema, normalize } from 'normalizr';

// Define course schema
const course = new schema.Entity('courses');

// Create function to normalize courses
export const coursesNormalizer = (data) => normalize(data, [course]);
