console.log('hello');

var x = 'this is global!';
var f = function() {
    console.log('from f');
};

var d = {
    x: 67,
    var2: 'hello',
    f: f,
    f1: function() {
        console.log('from d');
    },
    f2: function() {
        x = this.x + 45;
        console.log(x);
    },
    3: 4
};
/*
var maker = {
    foo: 0,
    makeIncrementer: function() {
        return ++this.foo;
    }
};

var makeIncrementer = maker.makeIncrementer;
*/

var makeIncrementer = function() {
    var foo = 0;
    return function() {
        return ++foo;
    }
};

var makeCounter = function() {
    var c = 0;
    
    var get = function() {
        return c;
    };
    
    var inc = function() {
        return ++c;
    };
    
    var dec = function() {
        return --c;
    };
    
    return {
        get: get,
        inc: inc,
        dec: dec
    };
};
