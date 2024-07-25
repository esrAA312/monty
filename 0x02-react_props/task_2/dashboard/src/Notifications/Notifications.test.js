import React from 'react';
import { shallow } from 'enzyme';
import Notifications from './Notifications';
import NotificationItem from '../NotificationItem/NotificationItem';

// Configure Enzyme
import Enzyme from 'enzyme';
import Adapter from 'enzyme-adapter-react-16';

Enzyme.configure({ adapter: new Adapter() });

describe('Notifications Component', () => {
  it('renders without crashing', () => {
    shallow(<Notifications />);
  });

  it('renders three NotificationItem components', () => {
    const wrapper = shallow(<Notifications />);
    expect(wrapper.find(NotificationItem).length).toBe(3);
  });

  it('renders the first NotificationItem element with the correct html', () => {
    const wrapper = shallow(<Notifications />);
    const firstNotificationItem = wrapper.find(NotificationItem).first();
    expect(firstNotificationItem.prop('type')).toBe('default');
    expect(firstNotificationItem.prop('value')).toBe('New course available');
  });
});
