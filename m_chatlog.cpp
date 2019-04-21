/*       +------------------------------------+
 *       | Inspire Internet Relay Chat Daemon |
 *       +------------------------------------+
 *
 *  InspIRCd: (C) 2002-2009 InspIRCd Development Team
 * See: http://www.inspircd.org/wiki/index.php/Credits
 *
 * This program is free but copyrighted software; see
 *          the file COPYING for details.
 *
 * Channel Chat Logging module (c) 2009-2011 Daniel Rich <drich@employees.org>
 *
 * ---------------------------------------------------
 */

#include "inspircd.h"

/* $ModDesc: A module which logs all chat to the ircd log at default loglevel. */

class ModuleChatLog : public Module
{
 private:
    std::vector<std::string> logexception;
 public:
    ModuleChatLog()
    {

        Implementation eventlist[] = { I_OnUserPreMessage };
        ServerInstance->Modules->Attach(eventlist, this, 1);
    }

    virtual ~ModuleChatLog()
    {
    }

    virtual ModResult OnUserPreMessage(User* user,void* dest,int target_type, std::string &text, char status, CUList &exempt_list)
    {

         if (target_type == TYPE_CHANNEL)
         {
              Channel* c = (Channel*)dest;

              ServerInstance->Logs->Log("m_chatlog",DEFAULT,"%s: <%s!%s@%s> %s",c->name.c_str(), user->nick.c_str(), user->ident.c_str(), user->host.c_str(), text.c_str());
         }
         return MOD_RES_PASSTHRU;
    }

    virtual Version GetVersion()
    {
        return Version("A module which logs all chat to the ircd log at default loglevel.",VF_VENDOR);
    }

};

MODULE_INIT(ModuleChatLog)
