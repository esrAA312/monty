import React from 'react';
import { shallow } from 'enzyme';
import Login from './Login';

// Configure Enzyme
import Enzyme from 'enzyme';
import Adapter from 'enzyme-adapter-react-16';

Enzyme.configure({ adapter: new Adapter() });

describe('Login Component', () => {
  it('renders without crashing', () => {
    shallow(<Login />);
  });

  it('renders 2 input tags and 2 label tags', () => {
    const wrapper = shallow(<Login />);
    expect(wrapper.find('input').length).toBe(2);
    expect(wrapper.find('label').length).toBe(2);
  });
});
