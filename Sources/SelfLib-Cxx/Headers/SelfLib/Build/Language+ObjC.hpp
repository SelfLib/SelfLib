//
//  SelfLib
//

#ifdef __OBJC__

#define SELFLIB_LANGUAGE_OBJC

#define SELFLIB_OBJC_CLASS(NAME) \
    @class NAME

#define SELFLIB_OBJC_PROTOCOL(NAME) \
    @protocol NAME

#define SELFLIB_OBJC_ENUM(TYPE, NAME)

#else

#define SELFLIB_OBJC_CLASS(NAME) \
    typedef struct _SELFLIB_OBJC_##NAME* NAME

#define SELFLIB_OBJC_PROTOCOL(NAME) \
    typedef struct _SELFLIB_OBJC_##NAME* NAME

#define SELFLIB_OBJC_ENUM(TYPE, NAME) \
    typedef TYPE NAME

#endif
