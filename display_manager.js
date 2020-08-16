var display_manager = require('./build/Release/display_manager');


module.exports = {

sleepDisplay: function sleepDisplay() {
    return display_manager.displaySleepRequest();
},

wakeupDisplay : function wakeupDisplay() {
    return display_manager.displayWakeupRequest();
},

enumerateDisplay : function enumerateDisplay() {
    return display_manager.enumerateAttachedDisplay();
},

lastInputTime: function lastInputTime(val = '') {
    if (val === '') {
        return display_manager.lastInputTime();
    }
    else {
        return val;
    }    
}
};

display_manager.displaySleepRequest();
