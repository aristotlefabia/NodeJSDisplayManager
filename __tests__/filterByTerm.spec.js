const display_manager = require('../display_manager.js');

//hh:mm:ss ms format check
const time_format = /^\d+\:\d{2}\:\d{2} \d{3}$/;


describe("Device Display Management", () => {
	
  test("sleepDisplay", () => {	
	expect(display_manager.sleepDisplay()).toEqual(1);
  });
  
  test("wakeupDisplay", () => {	
	expect(display_manager.wakeupDisplay()).toEqual(1);
  });
  
   
  test("enumerateDisplay : if system display count is 1 then test case will pass else it will fail", () => {	
	expect(display_manager.enumerateDisplay()).toEqual(1);
  });	
	
	
  //last input time will be tested for hh:mm: ss format returned by the function
  //since returned time varies
  test("lastInputTime : checks time format of the return value", () => {	
    var r =   display_manager.lastInputTime();
	expect(time_format.test(r)).toEqual(true);
  });
});