import courseReducer from './courseReducer';
import { FETCH_COURSE_SUCCESS, SELECT_COURSE, UNSELECT_COURSE } from '../actions/courseActionTypes';

describe('courseReducer', () => {
  const initialState = [];

  const courses = [
    { id: 1, name: 'ES6', credit: 60 },
    { id: 2, name: 'Webpack', credit: 20 },
    { id: 3, name: 'React', credit: 40 }
  ];

  it('should return the default state when no action is passed', () => {
    expect(courseReducer(undefined, {})).toEqual(initialState);
  });

  it('should return the data passed when the action FETCH_COURSE_SUCCESS is passed', () => {
    const action = { type: FETCH_COURSE_SUCCESS, data: courses };
    const expectedState = courses.map(course => ({
      ...course,
      isSelected: false,
    }));
    expect(courseReducer(undefined, action)).toEqual(expectedState);
  });

  it('should update the correct item when the action SELECT_COURSE is passed', () => {
    const initialStateWithCourses = courses.map(course => ({
      ...course,
      isSelected: false,
    }));
    const action = { type: SELECT_COURSE, index: 2 };
    const expectedState = initialStateWithCourses.map(course =>
      course.id === 2 ? { ...course, isSelected: true } : course
    );
    expect(courseReducer(initialStateWithCourses, action)).toEqual(expectedState);
  });

  it('should update the correct item when the action UNSELECT_COURSE is passed', () => {
    const initialStateWithCourses = courses.map(course => ({
      ...course,
      isSelected: course.id === 2,
    }));
    const action = { type: UNSELECT_COURSE, index: 2 };
    const expectedState = initialStateWithCourses.map(course =>
      course.id === 2 ? { ...course, isSelected: false } : course
    );
    expect(courseReducer(initialStateWithCourses, action)).toEqual(expectedState);
  });
});
