// src/actions/uiActionCreators.test.js
import configureMockStore from 'redux-mock-store';
import thunk from 'redux-thunk';
import fetchMock from 'fetch-mock';
import { loginRequest, loginSuccess, loginFailure } from './uiActionCreators';
import { LOGIN, LOGIN_SUCCESS, LOGIN_FAILURE } from './uiActionTypes';

const middlewares = [thunk];
const mockStore = configureMockStore(middlewares);

describe('loginRequest action creator', () => {
  afterEach(() => {
    fetchMock.restore();
  });

  it('dispatches LOGIN and LOGIN_SUCCESS on successful login', () => {
    fetchMock.getOnce('/login-success.json', {
      body: { email: 'test@example.com', name: 'Test User' },
      headers: { 'content-type': 'application/json' },
    });

    const expectedActions = [
      { type: LOGIN, email: 'test@example.com', password: 'password123' },
      { type: LOGIN_SUCCESS, user: { email: 'test@example.com', name: 'Test User' } },
    ];

    const store = mockStore({});

    return store.dispatch(loginRequest('test@example.com', 'password123')).then(() => {
      expect(store.getActions()).toEqual(expectedActions);
    });
  });

  it('dispatches LOGIN and LOGIN_FAILURE on failed login', () => {
    fetchMock.getOnce('/login-success.json', 500); // Simulate failure

    const expectedActions = [
      { type: LOGIN, email: 'test@example.com', password: 'password123' },
      { type: LOGIN_FAILURE, error: 'Network response was not ok' },
    ];

    const store = mockStore({});

    return store.dispatch(loginRequest('test@example.com', 'password123')).then(() => {
      expect(store.getActions()).toEqual(expectedActions);
    });
  });
});
