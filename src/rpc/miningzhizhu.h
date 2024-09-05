#ifndef BITCOIN_MININGZHIZHU_H
#define BITCOIN_MININGZHIZHU_H

#include "script/script.h"

#include <univalue.h>

#include <memory>

#include "consensus/params.h"
#include "node/context.h"
using namespace node;

/** call from zmq */
class  ZmqCallHandler{
public:
    std::string  getblocktemplateFromZmq();
    NodeContext* pNode;
};


#endif //BITCOIN_MININGZHIZHU_H