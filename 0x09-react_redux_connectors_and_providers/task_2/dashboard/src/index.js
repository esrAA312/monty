import React from 'react';
import ReactDOM from 'react-dom';
import { Provider } from 'react-redux';
import { createStore, applyMiddleware } from 'redux';
import { Map } from 'immutable';
import ReduxThunk from 'redux-thunk';

import App from './App/App';
import uiReducer, { initialState } from './reducers/uiReducer';

const store = createStore(uiReducer, Map(initialState), applyMiddleware(ReduxThunk));

ReactDOM.render(
  <React.StrictMode>
     <Provider store={store}>
      <App />
    </Provider>
  </React.StrictMode>,
  document.getElementById('root')
);
