import { fromJS } from 'immutable';
import notificationReducer from './notificationReducer';
import {
  FETCH_NOTIFICATIONS_SUCCESS,
  MARK_AS_READ,
  SET_TYPE_FILTER
} from '../actions/notificationActionTypes';

describe('notificationReducer', () => {
  const initialState = fromJS({
    notifications: {},
    filter: 'DEFAULT'
  });

  const notifications = [
    { id: 1, type: 'default', value: 'New course available' },
    { id: 2, type: 'urgent', value: 'New resume available' },
    { id: 3, type: 'urgent', value: 'New data available' }
  ];

  it('should return the default state when no action is passed', () => {
    expect(notificationReducer(undefined, {})).toEqual(initialState);
  });

  it('should return the data passed when the action FETCH_NOTIFICATIONS_SUCCESS is passed', () => {
    const action = { type: FETCH_NOTIFICATIONS_SUCCESS, data: notifications };
    const expectedState = fromJS({
      filter: 'DEFAULT',
      notifications: {
        '1': { id: 1, type: 'default', value: 'New course available', isRead: false },
        '2': { id: 2, type: 'urgent', value: 'New resume available', isRead: false },
        '3': { id: 3, type: 'urgent', value: 'New data available', isRead: false }
      }
    });
    expect(notificationReducer(undefined, action).toJS()).toEqual(expectedState.toJS());
  });

  it('should update the correct item when the action MARK_AS_READ is passed', () => {
    const action = { type: MARK_AS_READ, index: 2 };
    const initialStateWithNotifications = fromJS({
      filter: 'DEFAULT',
      notifications: {
        '1': { id: 1, type: 'default', value: 'New course available', isRead: false },
        '2': { id: 2, type: 'urgent', value: 'New resume available', isRead: false },
        '3': { id: 3, type: 'urgent', value: 'New data available', isRead: false }
      }
    });
    const expectedState = initialStateWithNotifications.setIn(['notifications', '2', 'isRead'], true);
    expect(notificationReducer(initialStateWithNotifications, action).toJS()).toEqual(expectedState.toJS());
  });

  it('should update the filter when the action SET_TYPE_FILTER is passed', () => {
    const action = { type: SET_TYPE_FILTER, filter: 'URGENT' };
    const initialStateWithNotifications = fromJS({
      filter: 'DEFAULT',
      notifications: {
        '1': { id: 1, type: 'default', value: 'New course available', isRead: false },
        '2': { id: 2, type: 'urgent', value: 'New resume available', isRead: false },
        '3': { id: 3, type: 'urgent', value: 'New data available', isRead: false }
      }
    });
    const expectedState = initialStateWithNotifications.set('filter', 'URGENT');
    expect(notificationReducer(initialStateWithNotifications, action).toJS()).toEqual(expectedState.toJS());
  });
});
