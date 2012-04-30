# Copyright (c) 2011 Dell Inc.

cmake_minimum_required (VERSION 2.8)

macro (target_link_framework exename fwname)
  find_library (FRAMEWORK_${fwname}
    NAMES ${fwname}
    PATHS ${CMAKE_OSX_SYSROOT}/System/Library
    PATH_SUFFIXES Frameworks
    NO_DEFAULT_PATH)
  if (${FRAMEWORK_${fwname}} STREQUAL FRAMEWORK_${fwname}-NOTFOUND)
    message (ERROR ": Framework ${fwname} not found")
  else ()
    target_link_libraries (${exename} ${FRAMEWORK_${fwname}})
    message (STATUS "Framework ${fwname} found at ${FRAMEWORK_${fwname}}")
  endif ()
endmacro (target_link_framework)


include_directories (
  .
  ${VENDOR_INSTALL_PREFIX}/include
  ${VENDOR_INSTALL_PREFIX}/include/openssl
  ${VENDOR_INSTALL_PREFIX}/include/srtp
)

link_directories (
  ${VENDOR_INSTALL_PREFIX}/lib
)

set (BASE_SOURCES
    talk/base/asyncfile.cc
    talk/base/asynchttprequest.cc
    #talk/base/asynchttprequest_unittest.cc
    talk/base/asyncpacketsocket.h
    #talk/base/asyncpacketsocket.cc
    talk/base/asyncsocket.cc
    talk/base/asyncsocket.h
    talk/base/asynctcpsocket.cc
    talk/base/asynctcpsocket.h
    talk/base/asyncudpsocket.cc
    talk/base/asyncudpsocket.h
    talk/base/atomicops.h
    #talk/base/atomicops_unittest.cc
    talk/base/autodetectproxy.cc
    talk/base/autodetectproxy.h
    #talk/base/autodetectproxy_unittest.cc
    talk/base/bandwidthsmoother.cc
    talk/base/bandwidthsmoother.h
    #talk/base/bandwidthsmoother_unittest.cc
    talk/base/base64.cc
    talk/base/base64.h
    #talk/base/base64_unittest.cc
    talk/base/basicdefs.h
    talk/base/basicpacketsocketfactory.cc
    talk/base/basicpacketsocketfactory.h
    talk/base/basictypes.h
    talk/base/buffer.h
    #talk/base/buffer_unittest.cc
    talk/base/bytebuffer.cc
    talk/base/bytebuffer.h
    #talk/base/bytebuffer_unittest.cc
    talk/base/byteorder.h
    talk/base/checks.cc
    talk/base/checks.h
    talk/base/common.cc
    talk/base/common.h
    talk/base/constructormagic.h
    talk/base/cpuid.cc
    talk/base/cpuid.h
    #talk/base/cpuid_unittest.cc
    talk/base/cpumonitor.cc
    talk/base/cpumonitor.h
    #talk/base/cpumonitor_unittest.cc
    talk/base/criticalsection.h
    talk/base/cryptstring.h
    talk/base/diskcache.cc
    talk/base/diskcache.h
    talk/base/Equifax_Secure_Global_eBusiness_CA-1.h
    talk/base/event.cc
    talk/base/event.h
    #talk/base/event_unittest.cc
    talk/base/fakenetwork.h
    talk/base/faketaskrunner.h
    talk/base/filelock.cc
    talk/base/filelock.h
    #talk/base/filelock_unittest.cc
    talk/base/fileutils.cc
    talk/base/fileutils.h
    talk/base/fileutils_mock.h
    #talk/base/fileutils_unittest.cc
    talk/base/firewallsocketserver.cc
    talk/base/firewallsocketserver.h
    talk/base/flags.cc
    talk/base/flags.h
    talk/base/gunit.h
    talk/base/helpers.cc
    talk/base/helpers.h
    #talk/base/helpers_unittest.cc
    talk/base/host.cc
    talk/base/host.h
    #talk/base/host_unittest.cc
    talk/base/httpbase.cc
    talk/base/httpbase.h
    #talk/base/httpbase_unittest.cc
    talk/base/httpclient.cc
    talk/base/httpclient.h
    talk/base/httpcommon-inl.h
    talk/base/httpcommon.cc
    talk/base/httpcommon.h
    #talk/base/httpcommon_unittest.cc
    talk/base/httprequest.cc
    talk/base/httprequest.h
    talk/base/httpserver.cc
    talk/base/httpserver.h
    #talk/base/httpserver_unittest.cc
    talk/base/ipaddress.cc
    talk/base/ipaddress.h
    #talk/base/ipaddress_unittest.cc
    talk/base/json.cc
    talk/base/json.h
    #talk/base/json_unittest.cc
    talk/base/linked_ptr.h
    talk/base/logging.cc
    talk/base/logging.h
    #talk/base/logging_unittest.cc
    talk/base/mathutils.h
    talk/base/md5.h
    talk/base/md5c.c
    talk/base/messagehandler.cc
    talk/base/messagehandler.h
    talk/base/messagequeue.cc
    talk/base/messagequeue.h
    #talk/base/messagequeue_unittest.cc
    talk/base/multipart.cc
    talk/base/multipart.h
    #talk/base/multipart_unittest.cc
    #talk/base/nat_unittest.cc
    talk/base/natserver.cc
    talk/base/natsocketfactory.cc
    talk/base/natsocketfactory.h
    talk/base/nattypes.cc
    talk/base/nattypes.h
    talk/base/nethelpers.cc
    talk/base/nethelpers.h
    talk/base/network.cc
    talk/base/network.h
    #talk/base/network_unittest.cc
    talk/base/openssladapter.cc
    talk/base/openssladapter.h
    talk/base/optionsfile.cc
    talk/base/optionsfile.h
    #talk/base/optionsfile_unittest.cc
    talk/base/packetsocketfactory.h
    talk/base/pathutils.cc
    talk/base/pathutils.h
    #talk/base/pathutils_unittest.cc
    talk/base/physicalsocketserver.cc
    talk/base/physicalsocketserver.h
    #talk/base/physicalsocketserver_unittest.cc
    talk/base/posix.cc
    talk/base/posix.h
    #talk/base/proxy_unittest.cc
    talk/base/proxydetect.cc
    talk/base/proxydetect.h
    #talk/base/proxydetect_unittest.cc
    talk/base/proxyinfo.cc
    talk/base/proxyinfo.h
    talk/base/proxyserver.cc
    talk/base/proxyserver.h
    talk/base/ratetracker.cc
    talk/base/ratetracker.h
    #talk/base/ratetracker_unittest.cc
    talk/base/refcount.h
    talk/base/referencecountedsingletonfactory.h
    #talk/base/referencecountedsingletonfactory_unittest.cc
    talk/base/rollingaccumulator.h
    #talk/base/rollingaccumulator_unittest.cc
    talk/base/scoped_autorelease_pool.h
    talk/base/scoped_autorelease_pool.mm
    talk/base/scoped_ptr.h
    talk/base/scoped_ref_ptr.h
    talk/base/sec_buffer.h
    talk/base/sharedexclusivelock.cc
    talk/base/sharedexclusivelock.h
    #talk/base/sharedexclusivelock_unittest.cc
    talk/base/signalthread.cc
    talk/base/signalthread.h
    #talk/base/signalthread_unittest.cc
    talk/base/sigslot.h
    talk/base/sigslotrepeater.h
    talk/base/socket.h
    #talk/base/socket_unittest.cc
    #talk/base/socket_unittest.h
    talk/base/socketadapters.cc
    talk/base/socketadapters.h
    talk/base/socketaddress.cc
    talk/base/socketaddress.h
    #talk/base/socketaddress_unittest.cc
    talk/base/socketaddresspair.cc
    talk/base/socketaddresspair.h
    talk/base/socketfactory.h
    talk/base/socketpool.cc
    talk/base/socketpool.h
    talk/base/socketserver.h
    talk/base/socketstream.cc
    talk/base/socketstream.h
    talk/base/ssladapter.cc
    talk/base/ssladapter.h
    talk/base/sslroots.h
    talk/base/sslsocketfactory.cc
    talk/base/sslsocketfactory.h
    talk/base/stream.cc
    talk/base/stream.h
    #talk/base/stream_unittest.cc
    talk/base/stringdigest.cc
    talk/base/stringdigest.h
    talk/base/stringencode.cc
    talk/base/stringencode.h
    #talk/base/stringencode_unittest.cc
    talk/base/stringutils.cc
    talk/base/stringutils.h
    #talk/base/stringutils_unittest.cc
    talk/base/systeminfo.cc
    talk/base/systeminfo.h
    #talk/base/systeminfo_unittest.cc
    talk/base/task.cc
    talk/base/task.h
    #talk/base/task_unittest.cc
    talk/base/taskparent.cc
    talk/base/taskparent.h
    talk/base/taskrunner.cc
    talk/base/taskrunner.h
    talk/base/testbase64.h
    talk/base/testclient.cc
    talk/base/testclient.h
    #talk/base/testclient_unittest.cc
    talk/base/testechoserver.h
    talk/base/testutils.h
    talk/base/thread.cc
    talk/base/thread.h
    #talk/base/thread_unittest.cc
    talk/base/time.cc
    #talk/base/time.h
    ##talk/base/time_unittest.cc
    talk/base/timeutils.cc
    talk/base/timeutils.h
    #talk/base/timeutils_unittest.cc
    talk/base/timing.cc
    talk/base/timing.h
    talk/base/transformadapter.cc
    talk/base/transformadapter.h
    #talk/base/unittest_main.cc
    talk/base/urlencode.cc
    talk/base/urlencode.h
    #talk/base/urlencode_unittest.cc
    talk/base/versionparsing.cc
    talk/base/versionparsing.h
    #talk/base/versionparsing_unittest.cc
    #talk/base/virtualsocket_unittest.cc
    talk/base/virtualsocketserver.cc
    talk/base/virtualsocketserver.h
    talk/base/worker.cc
    talk/base/worker.h
)
set (MAC_SOURCES
    talk/base/macasyncsocket.cc
    talk/base/macasyncsocket.h
    talk/base/maccocoasocketserver.h
    #talk/base/maccocoasocketserver.mm
    talk/base/maccocoathreadhelper.h
    talk/base/maccocoathreadhelper.mm
    talk/base/macconversion.cc
    talk/base/macconversion.h
    talk/base/macsocketserver.cc
    talk/base/macsocketserver.h
    #talk/base/macsocketserver_unittest.cc
    talk/base/macutils.cc
    talk/base/macutils.h
    #talk/base/macutils_unittest.cc
    talk/base/macwindowpicker.cc
    talk/base/macwindowpicker.h
    #talk/base/macwindowpicker_unittest.cc
)
set (LINUX_SOURCES
    talk/base/dbus.cc
    talk/base/dbus.h
    #talk/base/dbus_unittest.cc
    talk/base/latebindingsymboltable.cc
    talk/base/latebindingsymboltable.h
    #talk/base/latebindingsymboltable_unittest.cc
    talk/base/libdbusglibsymboltable.cc
    talk/base/libdbusglibsymboltable.h
    talk/base/linux.cc
    talk/base/linux.h
    #talk/base/linux_unittest.cc
    talk/base/linuxfdwalk.c
    talk/base/linuxfdwalk.h
    #talk/base/linuxfdwalk_unittest.cc
    talk/base/linuxwindowpicker.cc
    talk/base/linuxwindowpicker.h
    #talk/base/linuxwindowpicker_unittest.cc

    # TODO - fix build for call example
    #talk/session/phone/gtkvideorenderer.cc
    #talk/session/phone/gtkvideorenderer.h
    talk/session/phone/libudevsymboltable.cc
    talk/session/phone/libudevsymboltable.h
    talk/session/phone/linphonemediaengine.cc
    talk/session/phone/linphonemediaengine.h
    talk/session/phone/linuxdevicemanager.cc
    talk/session/phone/linuxdevicemanager.h
    talk/session/phone/v4llookup.cc
    talk/session/phone/v4llookup.h
)
set (WIN32_SOURCES_
    talk/base/diskcache_win32.cc
    talk/base/diskcache_win32.h
    talk/base/schanneladapter.cc
    talk/base/schanneladapter.h
    talk/base/win32.cc
    talk/base/win32.h
    #talk/base/win32_unittest.cc
    talk/base/win32filesystem.cc
    talk/base/win32filesystem.h
    talk/base/win32regkey.cc
    talk/base/win32regkey.h
    #talk/base/win32regkey_unittest.cc
    talk/base/win32securityerrors.cc
    talk/base/win32socketinit.cc
    talk/base/win32socketinit.h
    talk/base/win32socketserver.cc
    talk/base/win32socketserver.h
    #talk/base/win32socketserver_unittest.cc
    talk/base/win32toolhelp.h
    #talk/base/win32toolhelp_unittest.cc
    talk/base/win32window.cc
    talk/base/win32window.h
    #talk/base/win32window_unittest.cc
    talk/base/win32windowpicker.cc
    talk/base/win32windowpicker.h
    #talk/base/win32windowpicker_unittest.cc
    talk/base/window.h
    talk/base/windowpicker.h
    talk/base/windowpickerfactory.h
    talk/base/winfirewall.cc
    talk/base/winfirewall.h
    #talk/base/winfirewall_unittest.cc
    talk/base/winping.cc
    talk/base/winping.h
    talk/session/phone/gdivideorenderer.cc
    talk/session/phone/gdivideorenderer.h
    talk/session/phone/win32devicemanager.cc
    talk/session/phone/win32devicemanager.h
)
set (NATSERVER_SOURCES
    talk/base/natserver.h
    talk/base/natserver_main.cc
)
set (CALL_EXAMPLE_SOURCES_
    talk/examples/call/call_main.cc
    #talk/examples/call/call_unittest.cc
    talk/examples/call/callclient.cc
    talk/examples/call/callclient.h
    #talk/examples/call/callclient_unittest.cc
    talk/examples/call/console.cc
    talk/examples/call/console.h
    talk/examples/call/discoitemsquerytask.cc
    talk/examples/call/discoitemsquerytask.h
    talk/examples/call/friendinvitesendtask.cc
    talk/examples/call/friendinvitesendtask.h
    talk/examples/call/mediaenginefactory.cc
    talk/examples/call/mediaenginefactory.h
    talk/examples/call/muc.h
    talk/examples/call/mucinviterecvtask.cc
    talk/examples/call/mucinviterecvtask.h
    talk/examples/call/mucinvitesendtask.cc
    talk/examples/call/mucinvitesendtask.h
    talk/examples/call/presenceouttask.cc
    talk/examples/call/presenceouttask.h
    talk/examples/call/presencepushtask.cc
    talk/examples/call/presencepushtask.h
    talk/examples/call/status.h
    talk/examples/call/voicemailjidrequester.cc
    talk/examples/call/voicemailjidrequester.h
)
set (CALL_EXAMPLE_SOURCES
    talk/examples/call/call_main.cc
    #talk/examples/call/call_unittest.cc
    talk/examples/call/callclient.cc
    talk/examples/call/callclient.h
    talk/examples/call/callclient_unittest.cc
    talk/examples/call/console.cc
    talk/examples/call/console.h
    talk/examples/call/discoitemsquerytask.cc
    talk/examples/call/discoitemsquerytask.h
    talk/examples/call/friendinvitesendtask.cc
    talk/examples/call/friendinvitesendtask.h
    talk/examples/call/mediaenginefactory.cc
    talk/examples/call/mediaenginefactory.h
    talk/examples/call/muc.h
    talk/examples/call/mucinviterecvtask.cc
    talk/examples/call/mucinviterecvtask.h
    talk/examples/call/mucinvitesendtask.cc
    talk/examples/call/mucinvitesendtask.h
    talk/examples/call/presenceouttask.cc
    talk/examples/call/presenceouttask.h
    talk/examples/call/presencepushtask.cc
    talk/examples/call/presencepushtask.h
    talk/examples/call/status.h
    talk/examples/call/voicemailjidrequester.cc
    talk/examples/call/voicemailjidrequester.h
)
set (LOGIN_EXAMPLE_SOURCES
    talk/examples/login/autoportallocator.h
    talk/examples/login/jingleinfotask.cc
    talk/examples/login/jingleinfotask.h
    talk/examples/login/login_main.cc
    talk/examples/login/xmppauth.cc
    talk/examples/login/xmppauth.h
    talk/examples/login/xmpppump.cc
    talk/examples/login/xmpppump.h
    talk/examples/login/xmppsocket.cc
    talk/examples/login/xmppsocket.h
    talk/examples/login/xmppthread.cc
    talk/examples/login/xmppthread.h
)
set (PCP_EXAMPLE_SOURCES
    talk/examples/pcp/pcp_main.cc
    talk/examples/login/jingleinfotask.cc
    talk/examples/login/jingleinfotask.h
)
set (PLUS_EXAMPLE_SOURCES
    talk/examples/plus/libjingleplus.cc
    talk/examples/plus/libjingleplus.h
    talk/examples/plus/presencepushtask.cc
    talk/examples/plus/presencepushtask.h
    talk/examples/plus/rostertask.cc
    talk/examples/plus/rostertask.h
    talk/examples/plus/testutil/libjingleplus_main.cc
    talk/examples/plus/testutil/libjingleplus_test_notifier.h
    talk/examples/plus/testutil/libjingleplus_unittest.cc
)
set (PEERCONNECTION_EXAMPLE_SOURCES
    talk/examples/peerconnection/client/conductor.cc
    talk/examples/peerconnection/client/conductor.h
    talk/examples/peerconnection/client/defaults.cc
    talk/examples/peerconnection/client/defaults.h
    talk/examples/peerconnection/client/linux/main.cc
    talk/examples/peerconnection/client/linux/main_wnd.cc
    talk/examples/peerconnection/client/linux/main_wnd.h
    talk/examples/peerconnection/client/main.cc
    talk/examples/peerconnection/client/main_wnd.cc
    talk/examples/peerconnection/client/main_wnd.h
    talk/examples/peerconnection/client/peer_connection_client.cc
    talk/examples/peerconnection/client/peer_connection_client.h
    talk/examples/peerconnection/server/data_socket.cc
    talk/examples/peerconnection/server/data_socket.h
    talk/examples/peerconnection/server/main.cc
    talk/examples/peerconnection/server/peer_channel.cc
    talk/examples/peerconnection/server/peer_channel.h
    talk/examples/peerconnection/server/server_test.html
    talk/examples/peerconnection/server/utils.cc
    talk/examples/peerconnection/server/utils.h
)
set (P2P_SOURCES
    talk/p2p/base/candidate.h
    talk/p2p/base/common.h
    talk/p2p/base/constants.cc
    talk/p2p/base/constants.h
    talk/p2p/base/fakesession.h
    talk/p2p/base/p2ptransport.cc
    talk/p2p/base/p2ptransport.h
    talk/p2p/base/p2ptransportchannel.cc
    talk/p2p/base/p2ptransportchannel.h
    talk/p2p/base/p2ptransportchannel_unittest.cc
    talk/p2p/base/parsing.cc
    talk/p2p/base/parsing.h
    talk/p2p/base/port.cc
    talk/p2p/base/port.h
    talk/p2p/base/port_unittest.cc
    talk/p2p/base/portallocator.cc
    talk/p2p/base/portallocator.h
    talk/p2p/base/portallocatorsessionproxy.cc
    talk/p2p/base/portallocatorsessionproxy.h
    talk/p2p/base/portproxy.cc
    talk/p2p/base/portproxy.h
    talk/p2p/base/pseudotcp.cc
    talk/p2p/base/pseudotcp.h
    talk/p2p/base/pseudotcp_unittest.cc
    talk/p2p/base/rawtransport.cc
    talk/p2p/base/rawtransport.h
    talk/p2p/base/rawtransportchannel.cc
    talk/p2p/base/rawtransportchannel.h
    talk/p2p/base/relayport.cc
    talk/p2p/base/relayport.h
    talk/p2p/base/relayport_unittest.cc
    talk/p2p/base/relayserver.cc
    talk/p2p/base/relayserver.h
    talk/p2p/base/relayserver_main.cc
    talk/p2p/base/relayserver_unittest.cc
    talk/p2p/base/session.cc
    talk/p2p/base/session.h
    talk/p2p/base/session_unittest.cc
    talk/p2p/base/sessionclient.h
    talk/p2p/base/sessiondescription.cc
    talk/p2p/base/sessiondescription.h
    talk/p2p/base/sessionid.h
    talk/p2p/base/sessionmanager.cc
    talk/p2p/base/sessionmanager.h
    talk/p2p/base/sessionmessages.cc
    talk/p2p/base/sessionmessages.h
    talk/p2p/base/stun.cc
    talk/p2p/base/stun.h
    talk/p2p/base/stun_unittest.cc
    talk/p2p/base/stunport.cc
    talk/p2p/base/stunport.h
    talk/p2p/base/stunport_unittest.cc
    talk/p2p/base/stunrequest.cc
    talk/p2p/base/stunrequest.h
    talk/p2p/base/stunrequest_unittest.cc
    talk/p2p/base/stunserver.cc
    talk/p2p/base/stunserver.h
    talk/p2p/base/stunserver_main.cc
    talk/p2p/base/stunserver_unittest.cc
    talk/p2p/base/tcpport.cc
    talk/p2p/base/tcpport.h
    talk/p2p/base/testrelayserver.h
    talk/p2p/base/teststunserver.h
    talk/p2p/base/transport.cc
    talk/p2p/base/transport.h
    talk/p2p/base/transport_unittest.cc
    talk/p2p/base/transportchannel.cc
    talk/p2p/base/transportchannel.h
    talk/p2p/base/transportchannelimpl.h
    talk/p2p/base/transportchannelproxy.cc
    talk/p2p/base/transportchannelproxy.h
    talk/p2p/base/udpport.cc
    talk/p2p/base/udpport.h
    talk/p2p/client/basicportallocator.cc
    talk/p2p/client/basicportallocator.h
    talk/p2p/client/connectivitychecker.cc
    talk/p2p/client/connectivitychecker.h
    talk/p2p/client/connectivitychecker_unittest.cc
    talk/p2p/client/httpportallocator.cc
    talk/p2p/client/httpportallocator.h
    talk/p2p/client/portallocator_unittest.cc
    talk/p2p/client/sessionmanagertask.h
    talk/p2p/client/sessionsendtask.h
    talk/p2p/client/socketmonitor.cc
    talk/p2p/client/socketmonitor.h
    talk/session/phone/audioframe.h
    talk/session/phone/audiomonitor.cc
    talk/session/phone/audiomonitor.h
    talk/session/phone/call.cc
    talk/session/phone/call.h
    talk/session/phone/carbonvideorenderer.cc
    talk/session/phone/carbonvideorenderer.h
    talk/session/phone/channel.cc
    talk/session/phone/channel.h
    talk/session/phone/channel_unittest.cc
    talk/session/phone/channelmanager.cc
    talk/session/phone/channelmanager.h
    talk/session/phone/channelmanager_unittest.cc
    talk/session/phone/codec.cc
    talk/session/phone/codec.h
    talk/session/phone/codec_unittest.cc
    talk/session/phone/cryptoparams.h
    talk/session/phone/currentspeakermonitor.cc
    talk/session/phone/currentspeakermonitor.h
    talk/session/phone/currentspeakermonitor_unittest.cc
    talk/session/phone/devicemanager.cc
    talk/session/phone/devicemanager.h
    #talk/session/phone/devicemanager_mac.mm
    #talk/session/phone/devicemanager_unittest.cc
    talk/session/phone/dummydevicemanager.cc
    talk/session/phone/dummydevicemanager.h
    talk/session/phone/dummydevicemanager_unittest.cc
    talk/session/phone/fakedevicemanager.h
    talk/session/phone/fakemediaengine.h
    talk/session/phone/fakemediaprocessor.h
    talk/session/phone/fakenetworkinterface.h
    talk/session/phone/fakertp.h
    talk/session/phone/fakevideocapturer.h
    talk/session/phone/fakevideorenderer.h
    talk/session/phone/filemediaengine.cc
    talk/session/phone/filemediaengine.h
    talk/session/phone/filemediaengine_unittest.cc
    talk/session/phone/filevideocapturer.cc
    talk/session/phone/filevideocapturer.h
    talk/session/phone/filevideocapturer_unittest.cc
    talk/session/phone/macdevicemanager.cc
    talk/session/phone/macdevicemanager.h
    talk/session/phone/macdevicemanagermm.mm
    talk/session/phone/mediachannel.h
    talk/session/phone/mediacommon.h
    talk/session/phone/mediaengine.cc
    talk/session/phone/mediaengine.h
    talk/session/phone/mediamessages.cc
    talk/session/phone/mediamessages.h
    talk/session/phone/mediamessages_unittest.cc
    talk/session/phone/mediamonitor.cc
    talk/session/phone/mediamonitor.h
    talk/session/phone/mediaprocessorinterface.h
    talk/session/phone/mediarecorder.cc
    talk/session/phone/mediarecorder.h
    talk/session/phone/mediarecorder_unittest.cc
    talk/session/phone/mediasession.cc
    talk/session/phone/mediasession.h
    talk/session/phone/mediasession_unittest.cc
    talk/session/phone/mediasessionclient.cc
    talk/session/phone/mediasessionclient.h
    talk/session/phone/mediasessionclient_unittest.cc
    talk/session/phone/mediasink.h
    talk/session/phone/nullvideorenderer.h
    talk/session/phone/rtcpmuxfilter.cc
    talk/session/phone/rtcpmuxfilter.h
    talk/session/phone/rtcpmuxfilter_unittest.cc
    talk/session/phone/rtpdump.cc
    talk/session/phone/rtpdump.h
    talk/session/phone/rtpdump_unittest.cc
    talk/session/phone/rtputils.cc
    talk/session/phone/rtputils.h
    talk/session/phone/rtputils_unittest.cc
    talk/session/phone/screencastid.h
    talk/session/phone/soundclip.cc
    talk/session/phone/soundclip.h
    talk/session/phone/srtpfilter.cc
    talk/session/phone/srtpfilter.h
    #talk/session/phone/srtpfilter_unittest.cc
    talk/session/phone/ssrcmuxfilter.cc
    talk/session/phone/ssrcmuxfilter.h
    talk/session/phone/ssrcmuxfilter_unittest.cc
    talk/session/phone/streamparams.cc
    talk/session/phone/streamparams.h
    talk/session/phone/testdata/captured-320x240-2s-48.frames
    talk/session/phone/testdata/h264-svc-99-640x360.rtpdump
    talk/session/phone/testdata/video.rtpdump
    talk/session/phone/testdata/voice.rtpdump
    talk/session/phone/testutils.cc
    talk/session/phone/testutils.h
    talk/session/phone/videoadapter.cc
    talk/session/phone/videoadapter.h
    talk/session/phone/videocapturer.cc
    talk/session/phone/videocapturer.h
    talk/session/phone/videocapturer_unittest.cc
    talk/session/phone/videocommon.cc
    talk/session/phone/videocommon.h
    talk/session/phone/videocommon_unittest.cc
    talk/session/phone/videoframe.cc
    talk/session/phone/videoframe.h
    talk/session/phone/videoprocessor.h
    talk/session/phone/videorenderer.h
    talk/session/phone/videorendererfactory.h
    talk/session/phone/voicechannel.h
    talk/session/phone/voiceprocessor.h
    talk/session/tunnel/pseudotcpchannel.cc
    talk/session/tunnel/pseudotcpchannel.h
    talk/session/tunnel/securetunnelsessionclient.cc
    talk/session/tunnel/securetunnelsessionclient.h
    talk/session/tunnel/tunnelsessionclient.cc
    talk/session/tunnel/tunnelsessionclient.h
    #talk/session/tunnel/tunnelsessionclient_unittest.cc
)
set (LINUX_SOUND_SOURCES
    talk/sound/alsasoundsystem.cc
    talk/sound/alsasoundsystem.h
    talk/sound/alsasymboltable.cc
    talk/sound/alsasymboltable.h
    talk/sound/automaticallychosensoundsystem.h
    talk/sound/automaticallychosensoundsystem_unittest.cc
    talk/sound/linuxsoundsystem.cc
    talk/sound/linuxsoundsystem.h
    talk/sound/nullsoundsystem.cc
    talk/sound/nullsoundsystem.h
    talk/sound/nullsoundsystemfactory.cc
    talk/sound/nullsoundsystemfactory.h
    talk/sound/platformsoundsystem.cc
    talk/sound/platformsoundsystem.h
    talk/sound/platformsoundsystemfactory.cc
    talk/sound/platformsoundsystemfactory.h
    talk/sound/pulseaudiosoundsystem.cc
    talk/sound/pulseaudiosoundsystem.h
    talk/sound/pulseaudiosymboltable.cc
    talk/sound/pulseaudiosymboltable.h
    talk/sound/sounddevicelocator.h
    talk/sound/soundinputstreaminterface.h
    talk/sound/soundoutputstreaminterface.h
    talk/sound/soundsystemfactory.h
    talk/sound/soundsysteminterface.cc
    talk/sound/soundsysteminterface.h
    talk/sound/soundsystemproxy.cc
    talk/sound/soundsystemproxy.h
    talk/third_party/libudev/libudev.h
)
set (XMLLITE_SOURCES
    talk/xmllite/qname.cc
    talk/xmllite/qname.h
    talk/xmllite/qname_unittest.cc
    talk/xmllite/xmlbuilder.cc
    talk/xmllite/xmlbuilder.h
    talk/xmllite/xmlbuilder_unittest.cc
    talk/xmllite/xmlconstants.cc
    talk/xmllite/xmlconstants.h
    talk/xmllite/xmlelement.cc
    talk/xmllite/xmlelement.h
    talk/xmllite/xmlelement_unittest.cc
    talk/xmllite/xmlnsstack.cc
    talk/xmllite/xmlnsstack.h
    talk/xmllite/xmlnsstack_unittest.cc
    talk/xmllite/xmlparser.cc
    talk/xmllite/xmlparser.h
    talk/xmllite/xmlparser_unittest.cc
    talk/xmllite/xmlprinter.cc
    talk/xmllite/xmlprinter.h
    talk/xmllite/xmlprinter_unittest.cc
)
set (XMPP_SOURCES
    talk/xmpp/asyncsocket.h
    talk/xmpp/chatroommodule.h
    #talk/xmpp/chatroommodule_unittest.cc
    talk/xmpp/chatroommoduleimpl.cc
    talk/xmpp/constants.cc
    talk/xmpp/constants.h
    talk/xmpp/fakexmppclient.h
    talk/xmpp/hangoutpubsubclient.cc
    talk/xmpp/hangoutpubsubclient.h
    talk/xmpp/hangoutpubsubclient_unittest.cc
    talk/xmpp/iqtask.cc
    talk/xmpp/iqtask.h
    talk/xmpp/jid.cc
    talk/xmpp/jid.h
    talk/xmpp/jid_unittest.cc
    talk/xmpp/module.h
    talk/xmpp/moduleimpl.cc
    talk/xmpp/moduleimpl.h
    talk/xmpp/mucroomconfigtask.cc
    talk/xmpp/mucroomconfigtask.h
    talk/xmpp/mucroomconfigtask_unittest.cc
    talk/xmpp/mucroomhistorytask.cc
    talk/xmpp/mucroomhistorytask.h
    talk/xmpp/mucroomlookuptask.cc
    talk/xmpp/mucroomlookuptask.h
    talk/xmpp/mucroomlookuptask_unittest.cc
    talk/xmpp/plainsaslhandler.h
    talk/xmpp/prexmppauth.h
    talk/xmpp/pubsub_task.cc
    talk/xmpp/pubsub_task.h
    talk/xmpp/pubsubclient.cc
    talk/xmpp/pubsubclient.h
    talk/xmpp/pubsubclient_unittest.cc
    talk/xmpp/pubsubtasks.cc
    talk/xmpp/pubsubtasks.h
    talk/xmpp/pubsubtasks_unittest.cc
    talk/xmpp/ratelimitmanager.cc
    talk/xmpp/ratelimitmanager.h
    talk/xmpp/receivetask.cc
    talk/xmpp/receivetask.h
    #talk/xmpp/rostermodule.h
    #talk/xmpp/rostermoduleimpl.cc
    #talk/xmpp/rostermoduleimpl.h
    talk/xmpp/saslcookiemechanism.h
    talk/xmpp/saslhandler.h
    talk/xmpp/saslmechanism.cc
    talk/xmpp/saslmechanism.h
    talk/xmpp/saslplainmechanism.h
    talk/xmpp/util_unittest.cc
    talk/xmpp/util_unittest.h
    talk/xmpp/xmppclient.cc
    talk/xmpp/xmppclient.h
    talk/xmpp/xmppclientsettings.h
    talk/xmpp/xmppengine.h
    talk/xmpp/xmppengine_unittest.cc
    talk/xmpp/xmppengineimpl.cc
    talk/xmpp/xmppengineimpl.h
    talk/xmpp/xmppengineimpl_iq.cc
    talk/xmpp/xmpplogintask.cc
    talk/xmpp/xmpplogintask.h
    #talk/xmpp/xmpplogintask_unittest.cc
    talk/xmpp/xmppstanzaparser.cc
    talk/xmpp/xmppstanzaparser.h
    #talk/xmpp/xmppstanzaparser_unittest.cc
    talk/xmpp/xmpptask.cc
    talk/xmpp/xmpptask.h
)

# TODO - build out vendor to include webrtc
set (WEBRTC_SOURCES_
    talk/session/phone/fakewebrtccommon.h
    talk/session/phone/fakewebrtcdeviceinfo.h
    talk/session/phone/fakewebrtcvcmfactory.h
    talk/session/phone/fakewebrtcvideocapturemodule.h
    talk/session/phone/fakewebrtcvideoengine.h
    talk/session/phone/fakewebrtcvoiceengine.h
    talk/session/phone/webrtccommon.h
    talk/session/phone/webrtcmediaengine.h
    talk/session/phone/webrtcpassthroughrender.cc
    talk/session/phone/webrtcpassthroughrender.h
    talk/session/phone/webrtcpassthroughrender_unittest.cc
    talk/session/phone/webrtcvideocapturer.cc
    talk/session/phone/webrtcvideocapturer.h
    talk/session/phone/webrtcvideocapturer_unittest.cc
    talk/session/phone/webrtcvideoengine.cc
    talk/session/phone/webrtcvideoengine.h
    talk/session/phone/webrtcvideoengine_unittest.cc
    talk/session/phone/webrtcvideoframe.cc
    talk/session/phone/webrtcvideoframe.h
    talk/session/phone/webrtcvideoframe_unittest.cc
    talk/session/phone/webrtcvie.h
    talk/session/phone/webrtcvoe.h
    talk/session/phone/webrtcvoiceengine.cc
    talk/session/phone/webrtcvoiceengine.h
    talk/session/phone/webrtcvoiceengine_unittest.cc
)
set (WEBRTC_SOURCES
    talk/app/webrtc/audiotrackimpl.cc
    talk/app/webrtc/audiotrackimpl.h
    talk/app/webrtc/fakeportallocatorfactory.h
    talk/app/webrtc/mediastream.h
    talk/app/webrtc/mediastream_unittest.cc
    talk/app/webrtc/mediastreamhandler.cc
    talk/app/webrtc/mediastreamhandler.h
    talk/app/webrtc/mediastreamhandler_unittest.cc
    talk/app/webrtc/mediastreamimpl.cc
    talk/app/webrtc/mediastreamimpl.h
    talk/app/webrtc/mediastreamprovider.h
    talk/app/webrtc/mediastreamproxy.cc
    talk/app/webrtc/mediastreamproxy.h
    talk/app/webrtc/mediastreamtrackproxy.cc
    talk/app/webrtc/mediastreamtrackproxy.h
    talk/app/webrtc/mediatrackimpl.h
    talk/app/webrtc/notifierimpl.h
    talk/app/webrtc/peerconnection.h
    talk/app/webrtc/peerconnection_unittest.cc
    talk/app/webrtc/peerconnectionfactory_unittest.cc
    talk/app/webrtc/peerconnectionfactoryimpl.cc
    talk/app/webrtc/peerconnectionfactoryimpl.h
    talk/app/webrtc/peerconnectionimpl.cc
    talk/app/webrtc/peerconnectionimpl.h
    talk/app/webrtc/peerconnectionimpl_unittest.cc
    talk/app/webrtc/peerconnectionsignaling.cc
    talk/app/webrtc/peerconnectionsignaling.h
    talk/app/webrtc/peerconnectionsignaling_unittest.cc
    talk/app/webrtc/portallocatorfactory.cc
    talk/app/webrtc/portallocatorfactory.h
    talk/app/webrtc/roaperrorcodes.h
    talk/app/webrtc/roapmessages.cc
    talk/app/webrtc/roapmessages.h
    talk/app/webrtc/roapmessages_unittest.cc
    talk/app/webrtc/roapsession.cc
    talk/app/webrtc/roapsession.h
    talk/app/webrtc/roapsession_unittest.cc
    talk/app/webrtc/sessiondescriptionprovider.h
    talk/app/webrtc/streamcollectionimpl.h
    talk/app/webrtc/videorendererimpl.cc
    talk/app/webrtc/videotrackimpl.cc
    talk/app/webrtc/videotrackimpl.h
    talk/app/webrtc/webrtcjson.cc
    talk/app/webrtc/webrtcjson.h
    talk/app/webrtc/webrtcsdp.cc
    talk/app/webrtc/webrtcsdp.h
    talk/app/webrtc/webrtcsdp_unittest.cc
    talk/app/webrtc/webrtcsession.cc
    talk/app/webrtc/webrtcsession.h
    talk/app/webrtc/webrtcsession_unittest.cc
    talk/app/webrtc/webrtcsessionobserver.h
    talk/app/webrtcv1/peerconnection.h
    talk/app/webrtcv1/peerconnectionfactory.cc
    talk/app/webrtcv1/peerconnectionfactory.h
    talk/app/webrtcv1/peerconnectionimpl.cc
    talk/app/webrtcv1/peerconnectionimpl.h
    talk/app/webrtcv1/peerconnectionproxy.cc
    talk/app/webrtcv1/peerconnectionproxy.h
    talk/app/webrtcv1/webrtcjson.cc
    talk/app/webrtcv1/webrtcjson.h
    talk/app/webrtcv1/webrtcsession.cc
    talk/app/webrtcv1/webrtcsession.h
    talk/app/webrtcv1/webrtcsession_unittest.cc
)

set (POSIX_SOURCES
    talk/base/unixfilesystem.cc
    talk/base/unixfilesystem.h
    talk/base/opensslidentity.cc
    talk/base/opensslidentity.h
    talk/base/opensslstreamadapter.cc
    talk/base/opensslstreamadapter.h
    talk/base/sslidentity.cc
    talk/base/sslidentity.h
    #talk/base/sslidentity_unittest.cc
    talk/base/sslstreamadapter.cc
    talk/base/sslstreamadapter.h
    #talk/base/sslstreamadapter_unittest.cc
)


set (COMMON_SOURCES 
  ${BASE_SOURCES}
  ${P2P_SOURCES}
  ${XMLLITE_SOURCES}
  ${XMPP_SOURCES}
)

if (WIN32)
    set (JINGLE_SOURCES ${COMMON_SOURCES} ${WIN32_SOURCES_})
  add_definitions (/DFEATURE_ENABLE_SSL)
  add_definitions (/DFEATURE_ENABLE_VOICEMAIL)
  add_definitions (/DFEATURE_ENABLE_PSTN)
  add_definitions (/DHAVE_SRTP)
  add_definitions (/DSRTP_RELATIVE_PATH)
  add_definitions (/DEXPAT_RELATIVE_PATH)
  add_definitions (/DXML_STATIC)
  add_definitions (/wd4996)
  add_definitions (/D_CRT_SECURE_NO_WARNINGS)
  add_definitions (/D_SCL_SECURE_NO_WARNINGS)
  add_definitions (/D_USE_32BIT_TIME_T)
  add_definitions (/D_UNICODE)
  add_definitions (/DUNICODE)
  add_definitions (/DWIN32)
  add_definitions (/DWINVER=0x0500)
  add_definitions (/D_WIN32_WINNT=0x0501)
  add_definitions (/D_WIN32_IE=0x0501)
else ()
  if (APPLE)
    add_definitions (-DUSE_COCOA_THREADING)
    add_definitions (-Wno-deprecated-declarations)
    if (IOS)
      add_definitions (-DIOS)
      set (JINGLE_SOURCES ${COMMON_SOURCES} ${POSIX_SOURCES} ${MAC_SOURCES})
    else ()
      add_definitions (-DOSX)
      add_definitions (-fasm-blocks)
      set (JINGLE_SOURCES ${COMMON_SOURCES} ${POSIX_SOURCES} ${MAC_SOURCES} )
    endif ()
  else ()
    add_definitions (-DLINUX)
    add_definitions (-ffunction-sections)
    add_definitions (-fdata-sections)
    add_definitions (${GTK2_CFLAGS_OTHER})
    set (JINGLE_SOURCES ${COMMON_SOURCES} ${POSIX_SOURCES} ${LINUX_SOURCES})
  endif ()
  add_definitions (-DFEATURE_ENABLE_SSL)
  add_definitions (-DFEATURE_ENABLE_VOICEMAIL)
  add_definitions (-DFEATURE_ENABLE_PSTN)
  add_definitions (-DHAVE_SRTP)
  add_definitions (-DSRTP_RELATIVE_PATH)
  add_definitions (-DEXPAT_RELATIVE_PATH)
  add_definitions (-DXML_STATIC)
  add_definitions (-DHASHNAMESPACE=__gnu_cxx)
  add_definitions (-DHASH_NAMESPACE=__gnu_cxx)
  add_definitions (-DPOSIX)
  add_definitions (-DDISABLE_DYNAMIC_CAST)
  add_definitions (-DHAVE_OPENSSL_SSL_H=1)
  add_definitions (-D_REENTRANT)
  add_definitions (-fvisibility=hidden)
endif ()
add_definitions (-DJSONCPP_RELATIVE_PATH)
add_definitions (-DLIBJINGLE_UNITTEST)

#------------------------------------------------------------------------------
# library: jingle 
#------------------------------------------------------------------------------
add_library (jingle ${JINGLE_SOURCES})
message (STATUS "Adding Library: jingle")

if (APPLE AND IOS)
  set_target_properties(jingle PROPERTIES
                        XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET ${CMAKE_IPHONEOS_DEPLOYMENT_TARGET})
endif ()

install (TARGETS jingle DESTINATION ${CMAKE_JINGLE_INSTALL_DIR}/lib/release CONFIGURATIONS Release RelWithDebInfo MinSizeRel)
install (TARGETS jingle DESTINATION ${CMAKE_JINGLE_INSTALL_DIR}/lib/debug CONFIGURATIONS Debug)

install (DIRECTORY talk/ DESTINATION ${CMAKE_JINGLE_INSTALL_DIR}/include/talk FILES_MATCHING
         PATTERN "*.h"
         PATTERN "talk/third_party/*" EXCLUDE)


#------------------------------------------------------------------------------
# server: relayserver 
#------------------------------------------------------------------------------
if ( WIN32 OR (UNIX AND NOT IOS))
message (STATUS "Adding Server: relayserver")

add_executable (relayserver
  talk/p2p/base/relayserver_main.cc
)

add_dependencies (relayserver jingle)
target_link_libraries (relayserver jingle)

if (WIN32)
  target_link_libraries (relayserver libexpatMT secur32 crypt32 ws2_32)
else ()
  target_link_libraries (relayserver expat ssl crypto z)
  if (APPLE)
    if (IOS)
    else ()
      target_link_framework (relayserver Carbon Security)
    endif (IOS)
    target_link_framework (relayserver Foundation SystemConfiguration)
  else ()
    target_link_libraries (relayserver dl pthread)
  endif (APPLE)
endif (WIN32)

install (TARGETS relayserver DESTINATION bin/release CONFIGURATIONS Release RelWithDebInfo MinSizeRel)
install (TARGETS relayserver DESTINATION bin/debug CONFIGURATIONS Debug)
endif ()

#------------------------------------------------------------------------------
# server: stunserver 
#------------------------------------------------------------------------------
if (WIN32 OR (UNIX AND NOT IOS))
message (STATUS "Adding Server: stunserver")

add_executable (stunserver
  talk/p2p/base/stunserver_main.cc
)

add_dependencies (stunserver jingle)
target_link_libraries (stunserver jingle)

if (WIN32)
  target_link_libraries (stunserver libexpatMT secur32 crypt32 ws2_32)
else ()
  target_link_libraries (stunserver expat ssl crypto z)
  if (APPLE)
    if (IOS)
    else ()
      target_link_framework (stunserver Carbon Security)
    endif (IOS)
    target_link_framework (stunserver Foundation SystemConfiguration)
  else ()
    target_link_libraries (stunserver dl pthread)
  endif (APPLE)
endif (WIN32)

install (TARGETS stunserver DESTINATION bin/release CONFIGURATIONS Release RelWithDebInfo MinSizeRel)
install (TARGETS stunserver DESTINATION bin/debug CONFIGURATIONS Debug)
endif (WIN32 OR (UNIX AND NOT IOS))

#------------------------------------------------------------------------------
# example: login 
#------------------------------------------------------------------------------
if (WIN32 OR NOT IOS)
message (STATUS "Adding Example: login")

add_executable (login
  talk/examples/login/login_main.cc

  talk/examples/login/xmppauth.cc
  talk/examples/login/xmppauth.h

  talk/examples/login/xmpppump.cc
  talk/examples/login/xmpppump.h

  talk/examples/login/xmppsocket.cc
  talk/examples/login/xmppsocket.h

  talk/examples/login/xmppthread.cc
  talk/examples/login/xmppthread.h
)

add_dependencies (login jingle)
target_link_libraries (login jingle)

if (WIN32)
  target_link_libraries (login libexpatMT secur32 crypt32 ws2_32)
else ()
  target_link_libraries (login expat ssl crypto z)
  if (APPLE)
    if (IOS)
    else ()
      target_link_framework (login Carbon)
      target_link_framework (login Security)
    endif ()
    target_link_framework (login Foundation)
    target_link_framework (login SystemConfiguration)
  else ()
    target_link_libraries (login dl pthread)
  endif (APPLE)
endif ()

install (TARGETS login DESTINATION bin/release CONFIGURATIONS Release RelWithDebInfo MinSizeRel)
install (TARGETS login DESTINATION bin/debug CONFIGURATIONS Debug)
endif ()

#------------------------------------------------------------------------------
# example: call
#------------------------------------------------------------------------------
#if (WIN32 OR (APPLE AND NOT IOS) )
if (WIN32 AND (APPLE AND NOT IOS) )
message (STATUS "Adding Example: call")

set( CMAKE_VERBOSE_MAKEFILE on )

add_executable (call
  talk/examples/login/xmppauth.cc
  talk/examples/login/xmppauth.h

  talk/examples/login/xmpppump.cc
  talk/examples/login/xmpppump.h

  talk/examples/login/xmppsocket.cc
  talk/examples/login/xmppsocket.h

  talk/examples/login/xmppthread.cc
  talk/examples/login/xmppthread.h

  ${CALL_EXAMPLE_SOURCES_}
)

add_dependencies (call jingle)
target_link_libraries (call jingle)

if (WIN32)
  target_link_libraries (call libexpatMT secur32 crypt32 ws2_32)
  target_link_libraries (call srtp iphlpapi strmiids winmm)
else ()
  target_link_libraries (call expat srtp ssl crypto z xml2 xslt)
  if (APPLE)
    if (IOS)
    else ()
      target_link_framework (call Carbon )
      target_link_framework (call QTKit )
      target_link_framework (call Quartz )
      target_link_framework (call QuartzCore )
    endif ()
    target_link_framework (call CoreAudio )
    target_link_framework (call Foundation )
  else ()
    target_link_libraries (call dl pthread ${GTK2_LIBRARIES})
  endif ()
endif ()

install (TARGETS call DESTINATION bin/release CONFIGURATIONS Release RelWithDebInfo MinSizeRel)
install (TARGETS call DESTINATION bin/debug CONFIGURATIONS Debug)
endif ()

#--------------------------------------------------------
# example: pcp - deprecated file sharing utility
#--------------------------------------------------------
if ((WIN32 OR NOT IOS))
message (STATUS "Adding Example: pcp")

add_executable (pcp
    #talk/examples/pcp/pcp_main.cc
  ${PCP_EXAMPLE_SOURCES}

  talk/examples/login/xmppauth.cc
  talk/examples/login/xmppauth.h

  talk/examples/login/xmpppump.cc
  talk/examples/login/xmpppump.h

  talk/examples/login/xmppsocket.cc
  talk/examples/login/xmppsocket.h

  talk/examples/login/xmppthread.cc
  talk/examples/login/xmppthread.h
)

add_dependencies (pcp jingle)
target_link_libraries (pcp jingle)

if (WIN32)
  target_link_libraries (pcp libexpatMT secur32 crypt32 ws2_32)
else ()
  target_link_libraries (pcp expat ssl crypto z)
  if (APPLE)
    if (IOS)
    else ()
      target_link_framework (pcp Carbon Security)
    endif ()
    target_link_framework (pcp Foundation )
    target_link_framework (pcp Security )
    target_link_framework (pcp SystemConfiguration )
  else ()
    target_link_libraries (pcp dl pthread)
  endif (APPLE)
endif ()

install (TARGETS pcp DESTINATION bin/release CONFIGURATIONS Release RelWithDebInfo MinSizeRel)
install (TARGETS pcp DESTINATION bin/debug CONFIGURATIONS Debug)
endif ()
