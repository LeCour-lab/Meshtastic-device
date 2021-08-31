#include "configuration.h"
#include "ReplyPlugin.h"
#include "LaCourPlugin.h"
#include "MeshService.h"
#include "main.h"

#include <assert.h>

LaCourPlugin *laCourPlugin;

MeshPacket *LaCourPlugin::allocReply()
{
    assert(currentRequest); // should always be !NULL
    auto req = *currentRequest;
    auto &p = req.decoded;
    // The incoming message is in p.payload
    DEBUG_MSG("LaCour received message from=0x%0x, id=%d, msg=%.*s\n", req.from, req.id, p.payload.size, p.payload.bytes);

    screen->print("LaCour sending reply\n");

    const char *replyStr = "LaCour PlugIn replying ...";
    auto reply = allocDataPacket();                      // Allocate a packet for sending
    reply->decoded.payload.size = strlen(replyStr); // You must specify how many bytes are in the reply
    memcpy(reply->decoded.payload.bytes, replyStr, reply->decoded.payload.size);

    return reply;
}
