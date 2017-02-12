
const Lang = imports.lang;
const Gio = imports.gi.Gio;
const Mainloop = imports.mainloop;

const InterfaceAlarm = <interface name="es.aleksander.Alarm">
<signal name="Beeeeeeeeep" />
</interface>;
const ProxyAlarm = Gio.DBusProxy.makeProxyWrapper(InterfaceAlarm);

let proxy = new ProxyAlarm(Gio.DBus.session,
			   'es.aleksander.Alarm',
			   '/es/aleksander/Alarm');
proxy.connectSignal('Beeeeeeeeep',
		    Lang.bind(this, function(proxy, sender_name) {
			print('\n\nBEEEEEEEEEEEEEEEEEEEEP!\n\n')
		    }));

Mainloop.run();
