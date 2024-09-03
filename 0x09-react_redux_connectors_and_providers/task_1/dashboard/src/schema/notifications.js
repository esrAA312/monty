import { schema, normalize } from 'normalizr';

// Define notification schema
const notification = new schema.Entity('notifications');

// Create function to normalize notifications
export const notificationsNormalizer = (data) => normalize(data, [notification]);
