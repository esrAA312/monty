import React from 'react';
import PropTypes from 'prop-types'; // ES6
import { StyleSheet, css } from 'aphrodite';
import { connect } from 'react-redux';

import Notifications from '../Notifications/Notifications';
import Header from '../Header/Header';
import Login from '../Login/Login';
import CourseList from '../CourseList/CourseList';
import Footer from '../Footer/Footer';
import { getLatestNotification } from '../utils/utils';
import BodySectionWithMarginBottom from '../BodySection/BodySectionWithMarginBottom';
import BodySection from '../BodySection/BodySection';
import { user, logOut } from './AppContext';
import AppContext from './AppContext';
import { displayNotificationDrawer, hideNotificationDrawer } from '../actions/uiActionCreators';


const listCourses = [
  { id: 1, name: 'ES6', credit: 60 },
  { id: 2, name: 'Webpack', credit: 20 },
  { id: 3, name: 'React', credit: 40 }
];

const listNotifications = [
  { id: 1, type: 'default', value: 'New course available' },
  { id: 2, type: 'urgent', value: 'New resume available' },
  { id: 3, type: 'urgent', html: { __html: getLatestNotification()} }
];

class App extends React.Component {
  constructor(props) {
    super(props);
    this.handleClick = this.handleClick.bind(this);
    this.logOut = this.logOut.bind(this);
    this.logIn = this.logIn.bind(this);
    this.markNotificationAsRead = this.markNotificationAsRead.bind(this);
    this.state = {
      user: user,
      logOut: this.logOut,
      listNotifications: listNotifications
    };
  }

  componentDidMount() {
    document.addEventListener("keydown", this.handleClick);
  }

  handleClick(event) {
    if (event.keyCode === 72 && event.ctrlKey) {
      alert('Logging you out');
      this.state.logOut();
    }
  }

  logIn(email, password) {
    this.setState({ user: { email: email, password: password, isLoggedIn: true } })
  }

  logOut() {
    this.setState({ user: user });
  }

  markNotificationAsRead(id) {
    this.setState({ listNotifications: this.state.listNotifications.filter(notification => { return notification.id !== id }) });
  }

  render() {
    const { user, logOut, listNotifications } = this.state;
    const { isLoggedIn, displayDrawer, displayNotificationDrawer, hideNotificationDrawer } = this.props;
  
    return (
      <AppContext.Provider value={{user: user, logOut: logOut}}>
        <Notifications listNotifications={listNotifications} displayDrawer={displayDrawer} 
                       handleDisplayDrawer={displayNotificationDrawer} handleHideDrawer={hideNotificationDrawer}
                       markNotificationAsRead={this.markNotificationAsRead}></Notifications>
        <div className='App'>
          <Header></Header>
          <div className={css(style.appBody)}>
            {isLoggedIn ? 
              <BodySectionWithMarginBottom title='Course list'>
                <CourseList listCourses={listCourses} ></CourseList>
              </BodySectionWithMarginBottom> : 
              <BodySectionWithMarginBottom title='Log in to continue'>
                <Login logIn={this.logIn}></Login>
              </BodySectionWithMarginBottom>}
            <BodySection title='News from the School'>
              <p>Some news</p>
            </BodySection>
          </div>
          <div className={css(style.appFooter)}>
            <Footer></Footer>
          </div>
        </div>
      </AppContext.Provider>
    );
  }
}

App.propTypes = {
  isLoggedIn: PropTypes.bool,
  displayDrawer: PropTypes.bool,
  displayNotificationDrawer: PropTypes.func,
  hideNotificationDrawer: PropTypes.func,
};

App.defaultProps = {
  isLoggedIn: false,
  displayDrawer: false,
  displayNotificationDrawer: () => {},
  hideNotificationDrawer: () => {},
};

const style = StyleSheet.create({
  appBody: {
    backgroundColor: '#fff',
    padding: '4rem',
    minHeight: '26rem',
  },
  appFooter: {
    backgroundColor: '#fff',
    textAlign: 'center',
    width: '100%',
    bottom: '0px',
    borderTop: '3px solid #e1354b',
    fontStyle: 'italic',
    padding: '1rem 0'
  }
});

export const mapStateToProps = (state) => {
  return {
    isLoggedIn: state.get("isUserLoggedIn"),
    displayDrawer: state.get("isNotificationDrawerVisible")
  };
};

const mapDispatchToProps = {
  displayNotificationDrawer,
  hideNotificationDrawer,
};

export default connect(mapStateToProps, mapDispatchToProps)(App);
 
