const agora = require("./agorasdk");
const path = require("path");
const fs = require("fs")
const EventEmitter = require("events")

class AgoraRecordSdk extends EventEmitter {
    constructor() {
        super();
        this.recording = new agora.NodeRecordingSdk();
        this.initEventHandler();
    }

    initEventHandler() {
        let self = this;
    
        let fire = (...args) => {
          setImmediate(() => {
            this.emit(...args)
          })
        }

        this.onEvent("joinchannel", (channel, uid) => {
            fire('joinchannel', channel, uid);
        });
        this.onEvent("error", (err, stat) => {
            fire('error', err, stat);
        });
        this.onEvent("userjoin", (err, stat) => {
            fire('userjoin', err, stat);
        });
        this.onEvent("userleave", (err, stat) => {
            fire('userleave', err, stat);
        });
    }

    joinChannel(key, name, uid, appid, storeFolder) {
        return new Promise((resolve, reject) => {
            let binPath = path.join(__dirname, "./src/sdk/bin/");
            fs.access(storeFolder, fs.constants.W_OK, (err) => {
                if(err) {
                    throw "folder not writable"
                }
                const json = {
                    Recording_Dir: `${storeFolder}`
                };
                const cfgPath = path.join(storeFolder, '/cfg.json')
                fs.writeFile(cfgPath, JSON.stringify(json), err => {
                    this.recording.joinChannel(key || null, name, binPath, appid, uid, cfgPath);
                    this.once("error", err => {
                        reject(err);
                    })
                    this.once("joinchannel", () => {
                        resolve();
                    });
                });
            });
    
        });
    }

    setMixLayout(layout) {
        return this.recording.setMixLayout(layout);
    }

    onEvent(event, cb) {
        return this.recording.onEvent(event, cb);
    };

    leaveChannel() {
        return this.recording.leaveChannel();
    }

    release() {
        return this.recording.release();
    }
}

module.exports = AgoraRecordSdk;