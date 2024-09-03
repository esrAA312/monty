import { mapStateToProps } from './App';
import { expect as expectChai } from 'chai';

var _ = require('lodash');
const { fromJS } = require('immutable');

describe('Test App.js', () =>{it('test that verify that the function returns the right object', (done) => {
    let state = fromJS({ isUserLoggedIn: true });
    const result = mapStateToProps(state);
    expectChai(_.isEqual(result, { isLoggedIn: true })).to.equal(true);
    done();
  });
});
