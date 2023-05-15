function checkIfInstanceOf(obj: any, classFunction: any): boolean {
    if (obj === null || obj === undefined || !classFunction) {
        return false;
    }

    let ctor: any = obj.constructor;

    while (ctor) {
        if (ctor === classFunction) {
            return true;
        }
        ctor = Object.getPrototypeOf(ctor.prototype)?.constructor;
    }

    return false;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */