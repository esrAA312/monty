import React from 'react';
import { shallow } from 'enzyme';
import Header from './Header';
import logo from '../assets/Holberton-logo.jpg';

// Configure Enzyme
import Enzyme from 'enzyme';
import Adapter from 'enzyme-adapter-react-16';

Enzyme.configure({ adapter: new Adapter() });

describe('Header Component', () => {
  it('renders without crashing', () => {
    shallow(<Header />);
  });

  it('renders an image and an h1 tag', () => {
    const wrapper = shallow(<Header />);
    expect(wrapper.find('img').prop('src')).toEqual(logo);
    expect(wrapper.find('h1').text()).toEqual('School dashboard');
  });
});
