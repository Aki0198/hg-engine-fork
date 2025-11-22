#include "../include/types.h"
#include "../include/script.h"
#include "../include/repel.h"
#include "../include/constants/file.h"

#define SCRIPT_NEW_CMD_REPEL_USE    0

#define SCRIPT_NEW_CMD_IV_TUTOR 1

#define SCRIPT_NEW_CMD_MAX          256

BOOL Script_RunNewCmd(SCRIPTCONTEXT *ctx) {
    u8 sw = ScriptReadByte(ctx);
    u16 UNUSED arg0 = ScriptReadHalfword(ctx);

    switch (sw) {
        case SCRIPT_NEW_CMD_REPEL_USE:;
#ifdef IMPLEMENT_REUSABLE_REPELS
            u16 most_recent_repel = Repel_GetMostRecent();
            SetScriptVar(arg0, most_recent_repel);
            Repel_Use(most_recent_repel, HEAPID_MAIN_HEAP);
#endif
            break;

case SCRIPT_NEW_CMD_IV_TUTOR:;
#ifdef IMPLEMENT_IV_TUTOR
            FieldSystem *fsys = ctx->fsys;
            struct PartyPokemon *pp;
            struct Party *party = SaveData_GetPlayerPartyPtr(fsys->savedata);
            u8 perfectiv = 31;
            u8 zeroiv = 0;
            u8 maxevs = 252;
            u8 maxfriendship = 255;
            u8 maxpp = 3;
            u16 masterball = 1; // Poke Balls
            u16 ultraball = 2;
            u16 greatball = 3;
            u16 pokeball = 4;
            u16 safariball = 5;
            u16 netball = 6;
            u16 diveball = 7;
            u16 nestball = 8;
            u16 repeatball = 9;
            u16 timerball = 10;
            u16 luxuryball = 11;
            u16 premierball = 12;
            u16 duskball = 13;
            u16 healball = 14; 
            u16 quickball = 15;
            u16 cherishball = 16;
            u16 fastball = 492; // Apricorn Balls
            u16 levelball = 493;
            u16 lureball = 494;
            u16 heavyball = 495;
            u16 loveball = 496;
            u16 friendball = 497;
            u16 moonball = 498;
            u16 sportball = 499;
            u16 parkball = 500;
            u16 stench = 1; // Abilities Gen 3
            u16 drizzle = 2;
            u16 speedboost= 3;
            u16 battlearmor= 4;
            u16 sturdy = 5;
            u16 damp = 6;
            u16 limber = 7;
            u16 sandveil = 8;
            u16 staticc = 9;
            u16 voltabsorb= 10;
            u16 waterabsorb = 11;
            u16 oblivious = 12;
            u16 cloudnine = 13;
            u16 compoundeyes = 14;
            u16 insomnia = 15;
            u16 runaway = 50;
            u16 immunity = 17;
            u16 flashfire = 18;
            u16 shielddust = 19;
            u16 owntempo = 20;
            u16 suctioncups = 21;
            u16 intimidate = 22;
            u16 roughskin = 24;
            u16 levitate = 26;
            u16 effectspore = 27;
            u16 synchronize = 28;
            u16 clearbody = 29;
            u16 naturalcure = 30;
            u16 lightningrod = 31;
            u16 serenegrace = 32;
            u16 swiftswim = 33;
            u16 chlorophyll = 34;
            u16 trace = 36;
            u16 hugepower = 37;
            u16 poisonpoint = 38;
            u16 innerfocus = 39;
            u16 magmaarmor = 40;
            u16 waterveil = 41;
            u16 magnetpull = 42;
            u16 soundproof = 43;
            u16 raindish = 44;
            u16 sandstream = 45;
            u16 pressure = 46;
            u16 thickfat = 47;
            u16 earlybird = 48;
            u16 flamebody = 49;
            u16 keeneye = 51;
            u16 hypercutter = 52;
            u16 pickup = 53;
            u16 hustle = 55;
            u16 cutecharm = 56;
            u16 stickyhold = 60;
            u16 shedskin = 61;
            u16 guts = 62;
            u16 marvelscale = 63;
            u16 liquidooze = 64;
            u16 overgrow = 65;
            u16 blaze = 66;
            u16 torrent = 67;
            u16 swarm = 68;
            u16 rockhead = 69;
            u16 drought = 70;
            u16 arenatrap = 71;
            u16 vitalspirit = 72;
            u16 whitesmoke = 73;
            u16 purepower = 74;
            u16 shellarmor = 75;
            u16 tangledfeet = 77; // Abilities Gen 4
            u16 motordrive= 78;
            u16 rivalry = 79;
            u16 steadfast = 80;
            u16 snowcloak = 81;
            u16 gluttony = 82;
            u16 angerpoint = 83;
            u16 unburden = 84;
            u16 heatproof = 85;
            u16 dryskin = 87;
            u16 download = 88;
            u16 ironfist = 89;
            u16 poisonheal = 90;
            u16 adaptability = 91;
            u16 skilllink = 92;
            u16 hydration = 93;
            u16 solarpower = 94;
            u16 quickfeet = 95;
            u16 sniper = 97;
            u16 magicguard = 98;
            u16 noguard = 99;
            u16 technician = 101;
            u16 leafguard = 102;
            u16 moldbreaker = 104;
            u16 superluck = 105;
            u16 aftermath = 106;
            u16 anticipation = 107;
            u16 forewarn = 108;
            u16 unaware = 109;
            u16 tintedlens = 110;
            u16 filter = 111;
            u16 scrappy = 113;
            u16 stormdrain = 114;
            u16 icebody = 115;
            u16 solidrock = 116;
            u16 snowwarning = 117;
            u16 frisk = 119;
            u16 reckless = 120;
            u16 pickpocket = 124; // Abilities Gen 5
            u16 sheerforce = 125;
            u16 unnerve = 127;
            u16 defiant = 128;
            u16 cursedbody = 130;
            u16 healer = 131;
            u16 weakarmor = 133;
            u16 multiscale = 136;
            u16 harvest = 139;
            u16 telepathy = 140;
            u16 overcoat = 142;
            u16 poisontouch = 143;
            u16 regenerator = 144;
            u16 bigpecks = 145;
            u16 sandrush = 146;
            u16 wonderskin = 147;
            u16 analytic = 148;
            u16 infiltrator = 151;
            u16 moxie = 153;
            u16 justified = 154;
            u16 rattled = 155;
            u16 magicbounce = 156;
            u16 sapsipper = 157;
            u16 sandforce = 159;
            u16 competitive = 172; // Abilities Other Gens
            u16 strongjaw = 173;
            u16 refrigerate = 174;
            u16 toughclaws = 181;
            u16 pixilate = 182;
            u16 berserk = 201;
            u16 slushrush = 202;
            u16 cudchew = 291;
            u16 sharpness = 292;
            u16 armortail = 296;
            u8 pos = GetScriptVar(0x8008);
            pp = Party_GetMonByIndex (party, pos);
            switch (arg0)
            {
            case 0:SetMonData(pp,MON_DATA_HP_IV, &perfectiv); // Change Ivs
            SetMonData(pp,MON_DATA_ATK_IV, &perfectiv);
            SetMonData(pp,MON_DATA_DEF_IV, &perfectiv);
            SetMonData(pp,MON_DATA_SPATK_IV, &perfectiv);
            SetMonData(pp,MON_DATA_SPDEF_IV, &perfectiv);
            SetMonData(pp,MON_DATA_SPEED_IV, &perfectiv);
            break;
            case 1:SetMonData(pp,MON_DATA_ATK_IV, &zeroiv);break;
            case 2:SetMonData(pp,MON_DATA_SPATK_IV, &zeroiv);break;
            case 3:SetMonData(pp,MON_DATA_SPEED_IV, &zeroiv);break; 
            case 4:SetMonData(pp,MON_DATA_HP_EV, &maxevs);break; // Change EVs
            case 5:SetMonData(pp,MON_DATA_ATK_EV, &maxevs);break;
            case 6:SetMonData(pp,MON_DATA_DEF_EV, &maxevs);break;
            case 7:SetMonData(pp,MON_DATA_SPEED_EV, &maxevs);break;
            case 8:SetMonData(pp,MON_DATA_SPATK_EV, &maxevs);break;
            case 9:SetMonData(pp,MON_DATA_SPDEF_EV, &maxevs);break;
            case 10:SetMonData(pp,MON_DATA_HP_EV, &maxevs); // Max EVs for every stat (Unused for now)
            SetMonData(pp,MON_DATA_ATK_EV, &maxevs);
            SetMonData(pp,MON_DATA_DEF_EV, &maxevs);
            SetMonData(pp,MON_DATA_SPEED_EV, &maxevs);
            SetMonData(pp,MON_DATA_SPATK_EV, &maxevs);
            SetMonData(pp,MON_DATA_SPDEF_EV, &maxevs);break;
            case 11:SetMonData(pp,MON_DATA_FRIENDSHIP, &maxfriendship);break; // Misc Friendship
            case 12:SetMonData(pp,MON_DATA_MOVE1PPUP, &maxpp); // PP UP
            SetMonData(pp,MON_DATA_MOVE2PPUP, &maxpp);
            SetMonData(pp,MON_DATA_MOVE3PPUP, &maxpp);
            SetMonData(pp,MON_DATA_MOVE4PPUP, &maxpp);break;
            case 13:SetMonData(pp,MON_DATA_POKEBALL, &masterball);break; // Poke Balls
            case 14:SetMonData(pp,MON_DATA_POKEBALL, &ultraball);break;
            case 15:SetMonData(pp,MON_DATA_POKEBALL, &greatball);break;
            case 16:SetMonData(pp,MON_DATA_POKEBALL, &pokeball);break;
            case 17:SetMonData(pp,MON_DATA_POKEBALL, &safariball);break;
            case 18:SetMonData(pp,MON_DATA_POKEBALL, &netball);break;
            case 19:SetMonData(pp,MON_DATA_POKEBALL, &diveball);break;
            case 20:SetMonData(pp,MON_DATA_POKEBALL, &nestball);break;
            case 21:SetMonData(pp,MON_DATA_POKEBALL, &repeatball);break;
            case 22:SetMonData(pp,MON_DATA_POKEBALL, &timerball);break;
            case 23:SetMonData(pp,MON_DATA_POKEBALL, &luxuryball);break;
            case 24:SetMonData(pp,MON_DATA_POKEBALL, &premierball);break;
            case 25:SetMonData(pp,MON_DATA_POKEBALL, &duskball);break;
            case 26:SetMonData(pp,MON_DATA_POKEBALL, &healball);break;
            case 27:SetMonData(pp,MON_DATA_POKEBALL, &quickball);break;
            case 28:SetMonData(pp,MON_DATA_POKEBALL, &cherishball);break;
            case 29:SetMonData(pp,MON_DATA_POKEBALL, &fastball);break; // Apricorn balls
            case 30:SetMonData(pp,MON_DATA_POKEBALL, &levelball);break;
            case 31:SetMonData(pp,MON_DATA_POKEBALL, &lureball);break;
            case 32:SetMonData(pp,MON_DATA_POKEBALL, &heavyball);break;
            case 33:SetMonData(pp,MON_DATA_POKEBALL, &loveball);break;
            case 34:SetMonData(pp,MON_DATA_POKEBALL, &friendball);break;
            case 35:SetMonData(pp,MON_DATA_POKEBALL, &moonball);break;
            case 36:SetMonData(pp,MON_DATA_POKEBALL, &sportball);break;
            case 37:SetMonData(pp,MON_DATA_POKEBALL, &parkball);break;
            case 38:SetMonData(pp,MON_DATA_ABILITY, &stench);break; // Abilities Gen 3
            case 39:SetMonData(pp,MON_DATA_ABILITY, &drizzle);break;
            case 40:SetMonData(pp,MON_DATA_ABILITY, &speedboost);break;
            case 41:SetMonData(pp,MON_DATA_ABILITY, &battlearmor);break;
            case 42:SetMonData(pp,MON_DATA_ABILITY, &sturdy);break;
            case 43:SetMonData(pp,MON_DATA_ABILITY, &damp);break;
            case 44:SetMonData(pp,MON_DATA_ABILITY, &limber);break;
            case 45:SetMonData(pp,MON_DATA_ABILITY, &sandveil);break;
            case 46:SetMonData(pp,MON_DATA_ABILITY, &staticc);break;
            case 47:SetMonData(pp,MON_DATA_ABILITY, &voltabsorb);break;
            case 48:SetMonData(pp,MON_DATA_ABILITY, &waterabsorb);break;
            case 49:SetMonData(pp,MON_DATA_ABILITY, &oblivious);break;
            case 50:SetMonData(pp,MON_DATA_ABILITY, &cloudnine);break;
            case 51:SetMonData(pp,MON_DATA_ABILITY, &compoundeyes);break;
            case 52:SetMonData(pp,MON_DATA_ABILITY, &insomnia);break;
            case 53:SetMonData(pp,MON_DATA_ABILITY, &runaway);break;
            case 54:SetMonData(pp,MON_DATA_ABILITY, &immunity);break;
            case 55:SetMonData(pp,MON_DATA_ABILITY, &flashfire);break;
            case 56:SetMonData(pp,MON_DATA_ABILITY, &shielddust);break;
            case 57:SetMonData(pp,MON_DATA_ABILITY, &owntempo);break;
            case 58:SetMonData(pp,MON_DATA_ABILITY, &suctioncups);break;
            case 59:SetMonData(pp,MON_DATA_ABILITY, &intimidate);break;
            case 60:SetMonData(pp,MON_DATA_ABILITY, &roughskin);break;
            case 61:SetMonData(pp,MON_DATA_ABILITY, &levitate);break;
            case 62:SetMonData(pp,MON_DATA_ABILITY, &effectspore);break;
            case 63:SetMonData(pp,MON_DATA_ABILITY, &synchronize);break;
            case 64:SetMonData(pp,MON_DATA_ABILITY, &clearbody);break;
            case 65:SetMonData(pp,MON_DATA_ABILITY, &naturalcure);break;
            case 66:SetMonData(pp,MON_DATA_ABILITY, &lightningrod);break;
            case 67:SetMonData(pp,MON_DATA_ABILITY, &serenegrace);break;
            case 68:SetMonData(pp,MON_DATA_ABILITY, &swiftswim);break;
            case 69:SetMonData(pp,MON_DATA_ABILITY, &chlorophyll);break;
            case 70:SetMonData(pp,MON_DATA_ABILITY, &trace);break;
            case 71:SetMonData(pp,MON_DATA_ABILITY, &hugepower);break;
            case 72:SetMonData(pp,MON_DATA_ABILITY, &poisonpoint);break;
            case 73:SetMonData(pp,MON_DATA_ABILITY, &innerfocus);break;
            case 74:SetMonData(pp,MON_DATA_ABILITY, &magmaarmor);break;
            case 75:SetMonData(pp,MON_DATA_ABILITY, &waterveil);break;
            case 76:SetMonData(pp,MON_DATA_ABILITY, &magnetpull);break;
            case 77:SetMonData(pp,MON_DATA_ABILITY, &soundproof);break;
            case 78:SetMonData(pp,MON_DATA_ABILITY, &raindish);break;
            case 79:SetMonData(pp,MON_DATA_ABILITY, &sandstream);break;
            case 80:SetMonData(pp,MON_DATA_ABILITY, &pressure);break;
            case 81:SetMonData(pp,MON_DATA_ABILITY, &thickfat);break;
            case 82:SetMonData(pp,MON_DATA_ABILITY, &earlybird);break;
            case 83:SetMonData(pp,MON_DATA_ABILITY, &flamebody);break;
            case 84:SetMonData(pp,MON_DATA_ABILITY, &keeneye);break;
            case 85:SetMonData(pp,MON_DATA_ABILITY, &hypercutter);break;
            case 86:SetMonData(pp,MON_DATA_ABILITY, &pickup);break;
            case 87:SetMonData(pp,MON_DATA_ABILITY, &hustle);break;
            case 88:SetMonData(pp,MON_DATA_ABILITY, &cutecharm);break;
            case 89:SetMonData(pp,MON_DATA_ABILITY, &stickyhold);break;
            case 90:SetMonData(pp,MON_DATA_ABILITY, &shedskin);break;
            case 91:SetMonData(pp,MON_DATA_ABILITY, &guts);break;
            case 92:SetMonData(pp,MON_DATA_ABILITY, &marvelscale);break;
            case 93:SetMonData(pp,MON_DATA_ABILITY, &liquidooze);break;
            case 94:SetMonData(pp,MON_DATA_ABILITY, &overgrow);break;
            case 95:SetMonData(pp,MON_DATA_ABILITY, &blaze);break;
            case 96:SetMonData(pp,MON_DATA_ABILITY, &torrent);break;
            case 97:SetMonData(pp,MON_DATA_ABILITY, &swarm);break;
            case 98:SetMonData(pp,MON_DATA_ABILITY, &rockhead);break;
            case 99:SetMonData(pp,MON_DATA_ABILITY, &drought);break;
            case 100:SetMonData(pp,MON_DATA_ABILITY, &arenatrap);break;
            case 101:SetMonData(pp,MON_DATA_ABILITY, &vitalspirit);break;
            case 102:SetMonData(pp,MON_DATA_ABILITY, &whitesmoke);break;
            case 103:SetMonData(pp,MON_DATA_ABILITY, &purepower);break;
            case 104:SetMonData(pp,MON_DATA_ABILITY, &shellarmor);break;
            case 105:SetMonData(pp,MON_DATA_ABILITY, &tangledfeet);break; // Abilities Gen 4
            case 106:SetMonData(pp,MON_DATA_ABILITY, &motordrive);break;
            case 107:SetMonData(pp,MON_DATA_ABILITY, &rivalry);break;
            case 108:SetMonData(pp,MON_DATA_ABILITY, &steadfast);break;
            case 109:SetMonData(pp,MON_DATA_ABILITY, &snowcloak);break;
            case 110:SetMonData(pp,MON_DATA_ABILITY, &gluttony);break;
            case 111:SetMonData(pp,MON_DATA_ABILITY, &angerpoint);break;
            case 112:SetMonData(pp,MON_DATA_ABILITY, &unburden);break;
            case 113:SetMonData(pp,MON_DATA_ABILITY, &heatproof);break;
            case 114:SetMonData(pp,MON_DATA_ABILITY, &dryskin);break;
            case 115:SetMonData(pp,MON_DATA_ABILITY, &download);break;
            case 116:SetMonData(pp,MON_DATA_ABILITY, &ironfist);break;
            case 117:SetMonData(pp,MON_DATA_ABILITY, &poisonheal);break;
            case 118:SetMonData(pp,MON_DATA_ABILITY, &adaptability);break;
            case 119:SetMonData(pp,MON_DATA_ABILITY, &skilllink);break;
            case 120:SetMonData(pp,MON_DATA_ABILITY, &hydration);break;
            case 121:SetMonData(pp,MON_DATA_ABILITY, &solarpower);break;
            case 122:SetMonData(pp,MON_DATA_ABILITY, &quickfeet);break;
            case 123:SetMonData(pp,MON_DATA_ABILITY, &sniper);break;
            case 124:SetMonData(pp,MON_DATA_ABILITY, &magicguard);break;
            case 125:SetMonData(pp,MON_DATA_ABILITY, &noguard);break;
            case 126:SetMonData(pp,MON_DATA_ABILITY, &technician);break;
            case 127:SetMonData(pp,MON_DATA_ABILITY, &leafguard);break;
            case 128:SetMonData(pp,MON_DATA_ABILITY, &moldbreaker);break;
            case 129:SetMonData(pp,MON_DATA_ABILITY, &superluck);break;
            case 130:SetMonData(pp,MON_DATA_ABILITY, &aftermath);break;
            case 131:SetMonData(pp,MON_DATA_ABILITY, &anticipation);break;
            case 132:SetMonData(pp,MON_DATA_ABILITY, &forewarn);break;
            case 133:SetMonData(pp,MON_DATA_ABILITY, &unaware);break;
            case 134:SetMonData(pp,MON_DATA_ABILITY, &tintedlens);break;
            case 135:SetMonData(pp,MON_DATA_ABILITY, &filter);break;
            case 136:SetMonData(pp,MON_DATA_ABILITY, &scrappy);break;
            case 137:SetMonData(pp,MON_DATA_ABILITY, &stormdrain);break;
            case 138:SetMonData(pp,MON_DATA_ABILITY, &icebody);break;
            case 139:SetMonData(pp,MON_DATA_ABILITY, &solidrock);break;
            case 140:SetMonData(pp,MON_DATA_ABILITY, &snowwarning);break;
            case 141:SetMonData(pp,MON_DATA_ABILITY, &frisk);break;
            case 142:SetMonData(pp,MON_DATA_ABILITY, &reckless);break;
            case 143:SetMonData(pp,MON_DATA_ABILITY, &pickpocket);break; // Gen 5
            case 144:SetMonData(pp,MON_DATA_ABILITY, &sheerforce);break;
            case 145:SetMonData(pp,MON_DATA_ABILITY, &unnerve);break;
            case 146:SetMonData(pp,MON_DATA_ABILITY, &defiant);break;
            case 147:SetMonData(pp,MON_DATA_ABILITY, &cursedbody);break;
            case 148:SetMonData(pp,MON_DATA_ABILITY, &healer);break;
            case 149:SetMonData(pp,MON_DATA_ABILITY, &weakarmor);break;
            case 150:SetMonData(pp,MON_DATA_ABILITY, &multiscale);break;
            case 151:SetMonData(pp,MON_DATA_ABILITY, &harvest);break;
            case 152:SetMonData(pp,MON_DATA_ABILITY, &telepathy);break;
            case 153:SetMonData(pp,MON_DATA_ABILITY, &overcoat);break;
            case 154:SetMonData(pp,MON_DATA_ABILITY, &poisontouch);break;
            case 155:SetMonData(pp,MON_DATA_ABILITY, &regenerator);break;
            case 156:SetMonData(pp,MON_DATA_ABILITY, &bigpecks);break;
            case 157:SetMonData(pp,MON_DATA_ABILITY, &sandrush);break;
            case 158:SetMonData(pp,MON_DATA_ABILITY, &wonderskin);break;
            case 159:SetMonData(pp,MON_DATA_ABILITY, &analytic);break;
            case 160:SetMonData(pp,MON_DATA_ABILITY, &infiltrator);break;
            case 161:SetMonData(pp,MON_DATA_ABILITY, &moxie);break;
            case 162:SetMonData(pp,MON_DATA_ABILITY, &justified);break;
            case 163:SetMonData(pp,MON_DATA_ABILITY, &rattled);break;
            case 164:SetMonData(pp,MON_DATA_ABILITY, &magicbounce);break;
            case 165:SetMonData(pp,MON_DATA_ABILITY, &sapsipper);break;
            case 166:SetMonData(pp,MON_DATA_ABILITY, &sandforce);break;
            case 167:SetMonData(pp,MON_DATA_ABILITY, &competitive);break; // Gen 6+
            case 168:SetMonData(pp,MON_DATA_ABILITY, &strongjaw);break;
            case 169:SetMonData(pp,MON_DATA_ABILITY, &refrigerate);break;
            case 170:SetMonData(pp,MON_DATA_ABILITY, &toughclaws);break;
            case 171:SetMonData(pp,MON_DATA_ABILITY, &pixilate);break;
            case 172:SetMonData(pp,MON_DATA_ABILITY, &berserk);break;
            case 173:SetMonData(pp,MON_DATA_ABILITY, &slushrush);break;
            case 174:SetMonData(pp,MON_DATA_ABILITY, &cudchew);break;
            case 175:SetMonData(pp,MON_DATA_ABILITY, &sharpness);break;
            case 176:SetMonData(pp,MON_DATA_ABILITY, &armortail);break;
            default:break;
            }
            RecalcPartyPokemonStats(pp);
#endif
            break;

        default: break;
    }

    return FALSE;
}
