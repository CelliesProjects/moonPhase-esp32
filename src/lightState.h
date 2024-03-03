#ifndef LIGHT_STATE_H
#define LIGHT_STATE_H

enum lightState_t {
  LS_OFF,
  LS_TEMPERATURE,
  LS_COLOR,
  LS_STROBO,
  //LS_COLORFADE,
  //LS_HEARTBEAT,
  LS_MAX /* PSEUDO ELEMENT - SHOULD STAY LAST ELEMENT! */
};

class lightState {
  public:
  lightState(){}
  ~lightState(){}
  lightState_t         state(){return _state;}
  const char *         stateStr(const lightState_t state){return _str[state];}
  void                 set(const lightState_t state){_state = state;}
  private:
  lightState_t _state{LS_OFF};
  const char *_str[LS_MAX] {
    "OFF",
    "TEMPERATURE",
    "COLOR",
    "STROBOSCOPE"
    //"colorfade",
    //"heartbeat",
  };
};
#endif
